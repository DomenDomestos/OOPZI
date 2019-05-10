// OOPZI_task4.cpp: определяет точку входа для приложения.
/*
	Написано Раковским Дмитрием БПЗ1601 вариант 21
	𝑦(𝑧) = 1− 𝑧5 − 𝑡ℎ(𝑧2)
*/
//
#include "head.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b;
	cout << "\nВведите реальную часть компексного числа, потом комплексную\n";
	cin >> a>>b;
	Complex h(a, b);
	cout << "\nРезультат работы функции y(z)=1-Z^5-th(z/2)\n";
	cout << y(h)<<"\n";
	system("pause");
	return 0;
}
