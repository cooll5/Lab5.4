#include <iostream>
#include <cmath>
using namespace std;
double S0(const int N)
{
	double s = 0;
	for (int i = 1; i <= N; i++) {
		double c = (1 + i / N) / (i * i);
		s += c;
	}
	return s;
}
double S1(const int N, const int i)
{
	double c = ((1 + i / N) / (i * i));
	if (i > N)
		return 0;
	else
		return c + S1(N, i+1);
}
double S2(const int N, const int i)
{
	double c = ((1 + i / N) / (i * i));
	if (i < 1)
		return 0;
	else
		return c + S2(N, i+1);
}
double S3(const int N, const int i, double t)
{
	double c = ((1 + i / N) / (i * i));
	t = t + c;
	if (i >= N)
		return t;
	else
		return S3(N, i+1, t);
}
double S4(const int N, const int i, double t)
{
	double c = ((1 + i / N) / (i * i));
	t = t + c;
	if (i <= 1)
		return t;
	else
		return S4(N, i+1, t);
}

int main()
{

	int N, i;
	cout << "N = "; cin >> N;
	cout << "i = "; cin >> i;
	cout << "(iter) S0 = " << S0(N) << endl;
	cout << "(rec up ++) S1 = " << S1(N, i) << endl;
	cout << "(rec up --) S2 = " << S2(N, i) << endl;
	cout << "(rec down ++) S3 = " << S3(N, i, 0) << endl;
	cout << "(rec down --) S4 = " << S4(N, i, 0) << endl;
	return 0;
}