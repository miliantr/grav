//непосредственно лр

#pragma once
#define _USE_MATH_DEFINES
#include "Oper.h"
#include <fstream>
#include <math.h>
#include <string>


double get_JD(double year, double month, double day, double hour, double minute, double second) {
	double	a = int((14 - month) / 12),
		Y = year + 4800 - a,
		M = month + 12 * a - 3,
		JDN = day + int((153 * M + 2) / 5) + 365 * Y + int(Y / 4) - int(Y / 100) + int(Y / 400) - 32045;
	return JDN + (hour - 12) / 24 + minute / 1440 + second / 86400;
}

class Tmodel {
protected:
	Tvector X0; 
	Tmatrix Result;
	long double t0, tk, h;
	int countRes=0;
public:
	Tmodel(long double t0, long double tk, long double h, Tvector X0) {
		this->t0 = t0;
		this->tk = tk;
		this->h = h;
		this->X0 = X0; 
		int n = (tk - t0) / h;
		Result.resize(X0.get().size()+1, n);
	}
	long double get(int i) {
		if (i == 0)	
			return t0;
		else if (i == 1)
			return tk;
		else if (i < 0)
			return h;
	}
	Tvector get_X0() {
		return X0;
	}
	virtual Tvector RightParts(Tvector X) = 0;
	virtual void addResult(Tvector par, long double time) {
		if (countRes == Result.get()[0].size())
			Result.resize(Result.get().size(), Result.get()[0].size() + 5);
		Result(0, countRes) = time;
		double temp = 0;
		for (int i = 0; i < par.size(); i++) {
			temp = par(i);
			Result(i + 1, countRes) = temp;
		}
		countRes++;
		
	}
	void clr_Results() {
		for (int i = 0; i < Result.get_size_i(); i++)
			for (int j = 0; j < Result.get_size_j(); j++)
				Result(i, j) = 0;
		countRes = 0;
	}
	Tmatrix get_Result() {
		if (countRes < Result.get()[0].size())
			Result.resize(Result.get().size(), countRes);
		return Result;
	}
};






















class TArenst : public Tmodel {
protected:
	long double mu = 0.012277471, mu_=1-mu;
public:
	TArenst(long double t0, long double tk, long double h, Tvector X0) :Tmodel(t0, tk, h, X0) {};
	Tvector RightParts(Tvector X) override {//y1, y2, y'1, y'2
		Tvector temp(X0.get().size());		//y'1, y'2, y''1, y''2
		long double D1, D2;
		D1 = powl(powl(X(0) + mu, 2) + powl(X(1),2), 1.5);
		D2 = powl(powl(X(0) - mu_, 2) + powl(X(1), 2), 1.5);
		temp(0) = X(2);						//y'1=y'1
		temp(1) = X(3);						//y'2=y'2
		temp(2) = X(0) + 2 * X(3) - mu_ * (X(0) + mu) / D1 - mu * (X(0) - mu_) / D2;	//y''1
		temp(3) = X(1) - 2 * X(2) - mu_ * X(1) / D1 - mu * X(1) / D2;					//y''2
		return temp;
	}
};

class Tmatpen : public Tmodel {
protected:
	long double g = 9.81, l = 1;
public:
	Tmatpen(long double t0, long double tk, long double h, Tvector X0) :Tmodel(t0, tk, h, X0) {};
	void Set_Length(long double l) {
		this->l = l;
	}
	Tvector RightParts(Tvector X) override {
		Tvector temp(2);
		temp(0) = X(1);						//ph'
		temp(1) = (-g / l) * sinl(X(0));	//ph''
		return temp;
	}
};

class Trealpen : public Tmatpen {
protected:
	long double k = 0.5;
public:
	Trealpen(long double t0, long double tk, long double h, Tvector X0) :Tmatpen(t0, tk, h, X0) {};
	void Set_Zatuhanie(long double k) {
		this->k = k;
	}
	Tvector RightParts(Tvector X) override {
		Tvector temp(2);
		temp(0) = X(1);								//ph'
		temp(1) = (-g / l) * sinl(X(0)) - k * X(1);	//ph''
		return temp;
	}
};

class Tidealspring : public Tmodel {
protected:
	long double m = 0.1, g = 9.81, k = 5.5;
public:
	Tidealspring(long double t0, long double tk, long double h, Tvector X0) :Tmodel(t0, tk, h, X0) {};
	void set_mass(long double mass) {
		m = mass;
	}
	void set_Kupr(long double k) {
		this->k = k;
	}
	Tvector RightParts(Tvector X) override {
		Tvector temp(2);
		temp(0) = X(1);
		temp(1) = (-k / m) * X(0);
		return temp;
	}
};

class Trealspring_v : public Tidealspring {
protected:
	long double mu_v = 0.8;
public:
	Trealspring_v(long double t0, long double tk, long double h, Tvector X0) :Tidealspring(t0, tk, h, X0) {};
	void set_mu_v(long double mu_v) {
		this->mu_v = mu_v;
	}
	Tvector RightParts(Tvector X)override {
		Tvector temp(2);
		temp(0) = X(1);
		temp(1) = (-k / m) * X(0) - mu_v * X(1) / m;
		return temp;
	}
};
454554	3
class Trealspring_s : public Tidealspring {
protected:
	long double mu_s = 0.9;
	long double mus;
public:
	Trealspring_s(long double t0, long double tk, long double h, Tvector X0) :Tidealspring(t0, tk, h, X0) {};
	void set_mu_s(long double mu_s) {
		this->mu_s = mu_s;
	}
	Tvector RightParts(Tvector X) override {
		Tvector temp(2);
		if (X(1) > 0)
			mus = -mu_s;
		else if (X(1) < 0)
			mus = mu_s;
		else
			mus = 0.;
		temp(0) = X(1);
		temp(1) = (-k / m) * X(0) + mus * g;
		return temp;
	}
};

class TEarthModel : public Tmodel {
protected:
	const double mu = 132712.43994e6;
public:
	TEarthModel(long double t0, long double tk, long double h, Tvector X0) : Tmodel(t0, tk, h, X0) {};
	Tvector RightParts(Tvector X) override {//x-0, y-1, z-2, x'-3, y'-4, z'-5
		Tvector temp(X.get().size());		//x'-1, y'1-2, z'1-3, x''-3, y''-4, z''-5
		temp(0) = X(3);
		temp(1) = X(4);
		temp(2) = X(5);
		temp(3) = -mu * X(0) / pow(X.modul(), 3);
		temp(4) = -mu * X(1) / pow(X.modul(), 3);
		temp(5) = -mu * X(2) / pow(X.modul(), 3);
		return temp;
	}
};

class TSunIModel : public TEarthModel {
protected:
	const double RE = 6371.3, w = 7.292115e-5;
	double phi = 0, lambda = 0, date = 0, l = 100, time_befor = 0;
	bool flag, giga_flag = false;
	Tvector Dur_Day_sumt, TimeRise, TimeSS;
	int count_Day = 0, count_time = 0, UTC, month = 1, year = 2022, day = 1;
public:
	TSunIModel(double phi, double lambda, double date, long double t0, long double tk, long double h, Tvector X0, bool flag, int UTC) :
		TEarthModel(t0, tk, h, X0) {
		Dur_Day_sumt.resize(365);
		this->phi = phi*M_PI/180;
		this->lambda = lambda * M_PI / 180;
		this->date = date;	//DDMMYYYY
		this->flag = flag;	//false - 1 day, true - 365 days
		this->UTC = UTC;
		TimeRise.resize(365); TimeSS.resize(365);
	}
	double getSiderialTime(double Y, double M, double D, double h, double m, double s) {
		int a = (14 - M) / 12;
		M = M + 12 * a - 3;
		Y = Y + 4800 - a;
		double	JDN = D + int((153 * M + 2) / 5) + 365 * Y + int(Y / 4) - int(Y / 100) + int(Y / 400) - 32045,
				JD = JDN + (h - 12) / 24 + m / 1440 + s / 86400,
				t = int(JD - 2451544.5) / 36525,
				sG = 24110.54841 + 8640184.812866 * t + 0.093104 * t * t - t * t * t * 6.2e-6;
		return sG * M_PI / 180 + w * (h * 3600 + m * 60 + s) + lambda;
	}

	Tvector getDur_Day(int i) {
		switch (i) {
		case 0:	return Dur_Day_sumt;
		case 1: return TimeRise;
		case 2: return TimeSS;
		}
	}

	void addResult(Tvector par, long double time) override {//par - Re
		int h, m, sec, num_of_day = 0;

		if (flag) {
			num_of_day = int(time / 86400);
			if (num_of_day == 1)
				cout << endl;
			time_befor = time - num_of_day * 86400; //time_befor = h, но в секундах 
			h = int((time - num_of_day * 86400) / 3600);
			m = int((time - num_of_day * 86400 - h * 3600) / 60);
			sec = time - num_of_day * 86400 - h * 3600 - m * 60;

			if (num_of_day != count_Day) {
				Dur_Day_sumt(count_Day) = count_time * this->h;
				count_Day++;
				count_time = 0;
				if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day == 31) {
					day = 1;
					if (month == 12) {
						month = 1;
						year++;
					}
					else
						month++;
				}
				else if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30) {
					day = 1;
					month++;
				}
				else if (month == 2 && day == 28) {
					day = 1;
					month++;
				}
				day++;
			}
		}
		else {
			h = int(time / 3600);
			m = int((time - h * 3600) / 60);
			sec = time - h * 3600 - m * 60;
		}
		double s;
		if(flag)
			s = getSiderialTime(year, month, day, h, m, sec);
		else
			s = getSiderialTime(int(date) % 10000, int(date / 1e4) % 100, int(date / 1e6), h, m, sec);
		Tmatrix A({ {-cos(s) * sin(phi),	-sin(s) * sin(phi),	cos(phi)},
					{cos(phi) * cos(s),	cos(phi) * sin(s),	sin(phi)},
					{-sin(s),			cos(s),				0} });

		if (countRes == Result.get()[0].size())
			Result.resize(Result.get().size(), Result.get()[0].size() + 5);

		Result(0, countRes) = time;

		Tvector Re_, //re* 
			Re0, Rsh, Rg,
			Re({ par(0),par(1),par(2) }),
			r({ RE * cos(phi) * cos(s), RE * cos(phi) * sin(s), RE * sin(phi) }),
			r0;

		r0 = (1 / r.modul()) * r;
		Re0 = (1 / Re.modul()) * Re;
		Re_ = (-1 / (Re0 * r0)) * Re0;
		Rg = l * r0;
		Rsh = Rg + Re_;

		int point = 0;
		if (acos((Rsh * Re) / (Rsh.modul() * Re.modul())) >= M_PI_2) {
			point = 1;
		}
		ofstream Res_txt;  Res_txt.open("Result.txt", ios_base::app);

		double rRe = r * Re;

		if ((r0 * Re0 <= 0) && (giga_flag == false)) { //день + ночь = рассвет
			TimeRise(num_of_day) = time_befor;
			giga_flag = true;
		}
		if ((r0 * Re0 > 0) && (giga_flag==true)) { //ночь + день = закат
			TimeSS(num_of_day) = time_befor;
			giga_flag = false;
			Res_txt << TimeRise(num_of_day) << "\t\t" << TimeSS(num_of_day) << endl;
		}
		
		if (num_of_day == 365)
			cout << "work";

		Res_txt.close();

		Rsh = A * Rsh;	//Rsh -> Rsh(T)
		
		
		if (point) {
			for (int i = 0; i < Rsh.size(); i++)
				Result(i + 1, countRes) = Rsh(i);
			countRes++;
			if (flag)
				if ((time_befor+UTC*3600) >= 8*3600 && (time_befor+UTC*3600) <= 20*3600)
					count_time += 1;
		}
	}
};

class TGravityModel {
protected:
public:
	TGravityModel() {};
	virtual Tvector getAcceleration(Tvector X) = 0;
};

class TSatellite : public Tmodel {
protected:
	const double mu = 398600.4418e9;
	TGravityModel* gm; int flag;
	Tvector Orbit;	//w_big,i, w_lil, a, e, v0
					//	0	1	 2,	  3, 4, 5
	Tmatrix A(double v) {
		double w = Orbit(2),	i = Orbit(1),
			u = w + v,	W = Orbit(0);
		return Tmatrix({{cos(u) * cos(W) - sin(u) * sin(W) * cos(i),	-sin(u) * cos(W) - cos(u) * sin(W) * cos(i),	sin(i) * sin(W)},
						{cos(u) * sin(W) + sin(u) * cos(W) * cos(i),	-sin(u) * sin(W) + cos(u) * cos(W) * cos(i),	-sin(i) * cos(W)},
						{sin(u) * sin(i),								cos(u) * sin(i),								cos(i)} });
	}
public:
	TSatellite(long double t0, long double tk, long double h, Tvector X0) :Tmodel(t0, tk, h, X0) {
		Orbit.resize(6);
	};
	void SetOrbit(double Omega, double i, double omega, double a, double e, double v) {
		Orbit(0) = Omega;	Orbit(3) = a;
		Orbit(1) = i;		Orbit(4) = e;
		Orbit(2) = omega;	Orbit(5) = v;

		double p = a * (1 - e * e);
		Tvector r = A(v) * Tvector({ p / (1 + e * cos(v)), 0, 0 });
		Tvector V = A(v) * Tvector({ e * sin(v) * sqrt(mu / p), (1 + e * cos(v)) * sqrt(mu / p), 0 });
		this->X0 = Tvector({ r(0), r(1), r(2), 
			V(0), V(1), V(2) });
	}
	Tvector getOrbit() {
		return Orbit;
	}
	void setGM(TGravityModel* gm) {
		this->gm = gm;
	}
	Tvector RightParts(Tvector X)override {
		Tvector Y(6);
		Y(0) = X(3);
		Y(1) = X(4);
		Y(2) = X(5);
		Tvector g = gm->getAcceleration(X);
		Y(3) = g(0);
		Y(4) = g(1);
		Y(5) = g(2);
		return Y;
	}
};

class TEarthGravityModel : public TGravityModel {
protected:
	const double mu = 398600.4418e9;
	const double ae = 6378136;
public:
	TEarthGravityModel() :TGravityModel() {};
};

class TCentralGravityModel : public TEarthGravityModel {
public:
	TCentralGravityModel() :TEarthGravityModel() {};
	Tvector getAcceleration(Tvector X) override {
		return (-mu / pow(X.modul(),3)) * X;
	}
};

class TNormalGravityModel : public TEarthGravityModel {
protected:
	double Omega = 7.292115e-5; //угловая скорость
	double Cn[4], Jn[4] = {1082.62575e-6, -2.37089e-6, 6.08e-9, -1.4e-11};
	bool Q = false;
	Tvector sphericalToDecart(double ro, double phi, double lambda) {
		return Tvector({ ro * cos(phi) * cos(lambda), ro * cos(phi) * sin(lambda), ro * sin(phi) });
	}
	//lambda, phi, ro
	Tvector decardToSpherical(double x, double y, double z) {
		return Tvector({ atan2(y, x), atan2(z, sqrt(x * x + y * y)), sqrt(x * x + y * y + z * z) });
	}

	double delta(int k) {
		if (k == 0)
			return 0.5;
		else
			return 1.0;
	}

	double polynomLegendre(double phi, int n, int m) {
		if (n < m)
			return 0;
		else if (n == m && n == 0)
			return 1;
		else if (n > m) {
			double left = polynomLegendre(phi, n - 1, m) * sin(phi) * sqrt((4 * n * n - 1) / (double)(n * n - m * m)),
				right = polynomLegendre(phi, n - 2, m) * sqrt((pow(n - 1, 2) - m * m) * (2 * n + 1) / (double)((n * n - m * m) * (2 * n - 3)));
			return left - right;
		}
		else
			return polynomLegendre(phi, n - 1, m - 1) * cos(phi) * sqrt((2 * n + 1) / (double)(2 * n * delta(m - 1)));
	}
	double diffPolynomLegendre(double phi, int n) {
		return sqrt(0.5 * n * (n + 1)) * polynomLegendre(phi, n, 1);
	}

public:
	
	TNormalGravityModel() :TEarthGravityModel() {
		for (int i = 0; i < 4; i++)
			Cn[i] = -Jn[i] / sqrt(4 * (i + 1) + 1);
	}
	
	void SetQ(bool flag) {
		this->Q = flag;
	}
	
	Tvector getAcceleration(Tvector X) override {

		//Координаты объекта в сферических координатах: lambda, phi, ro 
		Tvector sp = decardToSpherical(X(0), X(1), X(2));
		//Вектор ускорения нормальной силы тяжести в сферических координатах и в прямоугольных
		Tvector g_sp(3), g_out(3);
		
		double sum = 0; int n = 0;
		for (int i = 0; i < 4; i++){
			n = 2 * (i + 1);
			sum = sum + (n + 1) * pow(ae / sp(2), n) * Cn[i] * polynomLegendre(sp(1), n, 0);
		}
		double temp=0;
		if (Q)
			temp = pow(Omega, 2) * sp(2) * pow(cos(sp(1)), 2);
		/*g_ro*/		g_sp(0) = -mu / pow(sp(2), 2) - mu * sum / pow(sp(2), 2) + temp;
		
		sum = 0;
		for (int i = 0; i < 4; i++) {
			n = 2 * (i + 1);
			sum = sum + pow(ae / sp(2), n) * Cn[i] * diffPolynomLegendre(sp(1), n);
		}
		if (Q)
			temp = pow(Omega, 2) * sp(2) * sin(2 * sp(1)) / 2;
		/*g_phi*/		g_sp(1) = sum * mu / pow(sp(2), 2) - temp;
		
		/*g_lambda*/	g_sp(2) = 0;

		double r0 = sqrt(X(0) * X(0) + X(1) * X(1));
		Tmatrix A({ {X(0)/sp(2),	-X(0)*X(2)/(sp(2)*r0),	-X(1)/r0},
					{X(1)/sp(2),	-X(1)*X(2)/(sp(2)*r0),	X(0)/r0 },
					{X(2)/sp(2),	r0/sp(2),				0} });

		if (r0 == 0) {
			A(0, 1) = 0;	A(0, 2) = 0;
			A(1, 1) = 0;	A(1, 2) = 0;
		}

		g_out = A * g_sp;
		
		return g_out;
	}
};

class TAnomalGravityModel : public TNormalGravityModel {
protected:
	static const int N = 60;
	double e[N];
	Tvector C[N];
public:
	TAnomalGravityModel() :TNormalGravityModel() {
		ifstream file("grav.txt");
		string tempE, tempX, tempY, tempZ;
		for (int i = 0; i < N; i++) {
			file >> tempE >> tempX >> tempY >> tempZ;
			e[i] = atof(tempE.c_str()) * 1e-10;
			C[i] = { atof(tempX.c_str()) * 1e3, atof(tempY.c_str()) * 1e3, atof(tempZ.c_str()) * 1e3 };
		}
		file.close();
	};
	Tvector getAcceleration(Tvector X) override {
		Tvector gn = TNormalGravityModel::getAcceleration(X);
		Tvector dg(3), r(3), x({X(0), X(1), X(2)});
		for (int i = 0; i < N; i++) {
			r = x + (-1) * C[i];
			dg = dg + (e[i] / powl(r.modul(), 3)) * (x + (-1) * C[i]);
		}
		dg = (-mu) * dg;
		return gn + dg;
	}
};