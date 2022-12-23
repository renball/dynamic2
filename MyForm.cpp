#include "MyForm.h"
#include <Windows.h>
#include <vector>
#include <fstream>
using namespace dynamic;
using namespace std;
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}
double g(double x, double y, double z,double omega0,double sigma) {
	double r;
	r = -2 * sigma * z - omega0 * omega0 * y;
	return r;
}
double f(double x,double y,double z,double omega0,double sigma) {
	return z;
}

double pi = 3.14;

System::Void dynamic::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	double Omega_0;
	double Sigma;
	double fi;
	double fidt;

	Omega_0 = Convert::ToDouble(textBox1->Text);
	Sigma = Convert::ToDouble(textBox2->Text);
	fi = Convert::ToDouble(textBox3->Text);
	fidt = Convert::ToDouble(textBox4->Text);

	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();



	double t = 0.0, dt = 0.001;
	double x,y, z;
	z = fidt; y = fi;
	double dy, dz, h, l1, l2, l3, l4, k1, k2, k3, k4;
	h = dt;
	while (t < 20.0) {

		k1 = h * f(x,y,z,Omega_0,Sigma);
		l1 = h * g(x,y,z, Omega_0, Sigma);
		k2 = h * f(x + h / 2, y + k1 / 2, z + l1 / 2, Omega_0, Sigma);
		l2 = h * g(x + h / 2, y + k1 / 2, z + l1 / 2, Omega_0, Sigma);
		k3 = h * f(x + h / 2, y + k2 / 2, z + l2 / 2, Omega_0, Sigma);
		l3 = h * g(x + h / 2, y + k2 / 2, z + l2 / 2, Omega_0, Sigma);
		k4 = h * f(x + h , y + k3, z + l3, Omega_0, Sigma);
		l4 = h * g(x + h, y + k3, z + l3, Omega_0, Sigma);

		dy =(k1 + 2*k2 + 2*k3 + k4)/6;
		dz =(l1 + 2 * l2 + 2 * l3 + l4)/6;

		y += dy;
		z += dz;

		t += h;
		this->chart1->Series[0]->Points->AddXY(t, y);
		this->chart1->Series[1]->Points->AddXY(t, z);
	}
	return System::Void();
}

System::Void dynamic::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	double Omega_0;
	double Sigma;
	double fi;
	double fidt;

	Omega_0 = Convert::ToDouble(textBox1->Text);
	Sigma = Convert::ToDouble(textBox2->Text);
	fi = Convert::ToDouble(textBox3->Text);
	fidt = Convert::ToDouble(textBox4->Text);

	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();



	double t = 0.0, dt = 0.001;
	double x, y, z;
	z = fidt; y = fi;
	double dy, dz, h, l1, l2, l3, l4, k1, k2, k3, k4;
	h = dt;
	while (t < 20.0) {

		k1 = h * f(x, y, z, Omega_0, Sigma);
		l1 = h * g(x, y, z, Omega_0, Sigma);
		k2 = h * f(x + h / 2, y + k1 / 2, z + l1 / 2, Omega_0, Sigma);
		l2 = h * g(x + h / 2, y + k1 / 2, z + l1 / 2, Omega_0, Sigma);
		k3 = h * f(x + h / 2, y + k2 / 2, z + l2 / 2, Omega_0, Sigma);
		l3 = h * g(x + h / 2, y + k2 / 2, z + l2 / 2, Omega_0, Sigma);
		k4 = h * f(x + h, y + k3, z + l3, Omega_0, Sigma);
		l4 = h * g(x + h, y + k3, z + l3, Omega_0, Sigma);

		dy = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		dz = (l1 + 2 * l2 + 2 * l3 + l4) / 6;

		y += dy;
		z += dz;

		t += h;
		this->chart1->Series[0]->Points->AddXY(y, z);
	}
	return System::Void();
}
