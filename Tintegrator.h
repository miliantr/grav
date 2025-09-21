#pragma once

#include "Tmodel.h"

#define max(p1, p2) (p1>p2?p1:p2)
#define min(p1, p2) (p1<p2?p1:p2)

class Tintegrator {
protected:
	long double eps = 1e-8;
public:
	Tintegrator() {}
	void SetEps(long double eps) {
		this->eps = eps;
	}
	virtual void Run(Tmodel* model) = 0;
};
//интегратор


class TDormand : public Tintegrator {
protected:
	long double c[7] = { 0, 1. / 5, 3. / 10, 4. / 5, 8. / 9, 1., 1. }, 
		a[7][6]= {
			{ 0. },
			{ 1. / 5 },
			{ 3. / 40, 9. / 40 },
			{ 44. / 45, -56. / 15, 32. / 9 },
			{ 19372. / 6561, -25360. / 2187, 64448. / 6561, -212. / 729 },
			{ 9017. / 3168, -355. / 33, 46732. / 5247, 49. / 176, -5103. / 18656 },
			{ 35. / 384, 0., 500. / 1113, 125. / 192, -2187. / 6784, 11. / 84 }
		},
		b1[7] = { 35. / 384, 0., 500. / 1113, 125. / 192, -2187. / 6784, 11. / 84, 0 }, 
		b2[7] = { 5179. / 57600, 0., 7571. / 16695, 393. / 640, -92097. / 339200, 187. / 2100, 1. / 40 };
	Tvector K[7];
	long double u;
public:
	TDormand() :Tintegrator() {
		long double v = 1;
		while (v + 1 > 1) {
			u = v;
			v /= 2;
		}
	}
	void Run(Tmodel* model) override {
		
		long double
			t = model->get(0), t_out = t, tk = model->get(1), 
			h, h_new = model->get(-1), e = 0, sum=0,sum1=0;
		
		Tvector X0 = model->get_X0(), Xk4(X0.get().size()), Xk5(X0.get().size()),
				X_res(X0.get().size()), Y(X0.get().size());
		
		for (int i = 7; i >0; --i, K[i].resize(X0.get().size()));
		
		int n = 0;
		
		while (t < tk) {
			
			// Устанавливаем шаг на итерацию
			h = h_new;
			// Вычисляем коэффициенты К
			for (int i = 0; i < 7; i++) {
				for (int j = 0; j < X0.get().size(); j++) {
					for (int k = 1; k <= i; k++)
						sum += a[i][k - 1] * K[k - 1](j)*h;
					Y(j) = X0(j) + sum; sum = 0;
				}
				K[i] = model->RightParts(Y);
			}

			// Вычисляем решения 4-го и 5-го порядков
			for (int j = 0; j < X0.get().size(); j++) {
				for (int i = 0; i < 7; i++) {
					sum += b1[i] * K[i](j)*h;
					sum1 += b2[i] * K[i](j)*h;
				}
				Xk4(j) = X0(j) + sum; sum = 0;
				Xk5(j) = X0(j) + sum1; sum1 = 0;
			}

			// Вычисляем значение локальной ошибки
			for (int j = 0; j < X0.get().size(); j++) {
				sum1 = max(max(1e-5, abs(Xk4(j))),max(abs(X0(j)),2*u/eps));
				sum += powl(h*(Xk4(j)-Xk5(j))/sum1,2);
			}
			e = sqrtl(sum / X0.get().size());
			sum = sum1 = 0;

			// Вычисляем новое значение шага
			sum1 = min(5, powl(e / eps, 0.2) / 0.9);
			h_new = h / max(0.1, sum1); sum1 = 0;

			// Если локальная ошибка превышает установленную величину, пытаемся сделать шаг заново
			if (e > eps)
				continue;

			// Формирование результатов при помощи механизма плотной выдачи
			while ((t_out < t + h) && (t_out <= tk)) {
				long double theta = (t_out - t) / h, b[6];
				
				// Рассчитываем коэффициенты плотной выдачи
				b[0] = theta * (1 + theta * (-1337. / 480. + theta * (1039. / 360. + theta * (-1163. / 1152.))));
				b[1] = 0;
				b[2] = 100. * powl(theta,2) * (1054. / 9275. + theta * (-4682. / 27825. + theta * (379. / 5565.))) / 3.;
				b[3] = -5. * powl(theta, 2) * (27. / 40. + theta * (-9. / 5. + theta * (83. / 96.))) / 2.;
				b[4] = 18225. * powl(theta, 2) * (-3. / 250. + theta * (22. / 375. + theta * (-37. / 600.))) / 848.;
				b[5] = -22. * powl(theta, 2) * (-3. / 10. + theta * (29. / 30. + theta * (-17. / 24.))) / 7.;
				
				// Получаем результат для выдачи
				for (int j = 0; j < X0.get().size(); j++) {
					sum = 0;
					for (int i = 0; i < 6; i++)
						sum += b[i] * K[i](j);
					X_res(j) = X0(j) + h * sum;
				}

				// Передача результата в модель
				model->addResult(X_res, t_out);

				// Наращиваем время выдачи
				t_out += model->get(-1);
			}

			// Обновляем X решением 5-го порядка и наращиваем время на величину сделанного шага
			X0 = Xk5;
			t += h;
			
			// Считаем количество итераций для вычисления глобальной погрешности
			n++;
		}
	}
};