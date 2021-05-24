//Source.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iostream>
#include <iomanip>
#include "Account.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Account x;
	x.Read();
	x.Display();

	x.Perc();
	x.Put();
	x.Withdraw();
	x.toDollar();
	x.toEuro();

	char s[100];
	strcpy(s, x.SumToNumeral());
	cout << "Сума на рахунку:" << s << endl << endl;
	x.SumToNumeral();

	double mult = 5;
	double div = 2;

	Account::Money A = MultToFractionsNumber(x.GetMoney(), mult);
	cout << "MultToFractionsNumber = " << A.get_sum() << endl;
	Account::Money B = DivisionToFractionsNumber(x.GetMoney(), div);
	cout << "DivisionToFractionsNumber = " << B.get_sum() << endl;

	Account y;


	y.Read();
	y.Display();
	//y.Perc();
	//y.Put();
	//y.Withdraw();
	//y.toDollar();
	//y.toEuro();

	char w[100];
	strcpy(w, y.SumToNumeral());
	cout << "Сума на рахунку:" << w << endl << endl;
	y.SumToNumeral();

	Account::Money X = MultToFractionsNumber(y.GetMoney(), mult);
	cout << "MultToFractionsNumber = " << X.get_sum() << endl;
	Account::Money Y = DivisionToFractionsNumber(y.GetMoney(), div);
	cout << "DivisionToFractionsNumber = " << Y.get_sum() << endl;

	Account::Money C = Addition(x.GetMoney(), y.GetMoney());
	cout << "Addition = " << C.get_sum() << endl;

	Account::Money D = Subtraction(x.GetMoney(), y.GetMoney());
	cout << "Substraction = " << D.get_sum() << endl;

	cout << "Division = " << Division(x.GetMoney(), y.GetMoney()) << endl;

	cout << "More = " << More(x.GetMoney(), y.GetMoney()) << endl;
	cout << "MoreEqual = " << MoreEqual(x.GetMoney(), y.GetMoney()) << endl;
	cout << "Less = " << Less(x.GetMoney(), y.GetMoney()) << endl;
	cout << "LessEqual = " << LessEqual(x.GetMoney(), y.GetMoney()) << endl;
	cout << "Equal = " << Equal(x.GetMoney(), y.GetMoney()) << endl;
	cout << "NonEqual = " << NonEqual(x.GetMoney(), y.GetMoney()) << endl;


	return 0;
}
