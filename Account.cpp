//Account.cpp
#include "Account.h"

void Account::SetMoney(Money value)
{
    money.Set_1000(value.Get_1000());
    money.Set_500(value.Get_500());
    money.Set_200(value.Get_200());
    money.Set_100(value.Get_100());
    money.Set_50(value.Get_50());
    money.Set_20(value.Get_20());
    money.Set_10(value.Get_10());
    money.Set_5(value.Get_5());
    money.Set_2(value.Get_2());
    money.Set_1(value.Get_1());
    money.Set_050(value.Get_050());
    money.Set_025(value.Get_025());
    money.Set_010(value.Get_010());
    money.Set_005(value.Get_005());
    money.Set_002(value.Get_002());
    money.Set_001(value.Get_001());
}
bool Account::SetNo(int value)
{
    if (value > 0)
    {
        no = value;
        return true;
    }
    else
    {
        no = 0;
        return false;
    }
}

bool Account::SetPercent(double value)
{
    if (value > 0)
    {
        percent = value;
        return true;
    }
    else
    {
        percent = -value;
        return false;
    }

}
bool Account::Init(int no, string name, Money money, double percent)
{
    SetName(name);
    SetMoney(money);
    return SetNo(no) && SetPercent(percent);
}
void Account::Read()
{
    string name;
    int no;
    Money a;
    double percent;
    do
    {
        cout << " no      = ? "; cin >> no;
        cout << " name  = ? ";   cin >> name;
        cout << " summa   = ? "; a.Read();
        cout << " percent = ? "; cin >> percent;
    } while (!Init(no, name, a, percent));
}
void Account::Display() const
{
    cout << toString() << endl;
}
string Account::toString() const
{
    stringstream sout;
    sout << " no    = " << no << endl;
    sout << " name  = " << name << endl;
    sout << " summa = " << money.get_sum() << endl;
    sout << " percent = " << percent << endl;

    return sout.str();
}
double Account::Withdraw()
{
    double sub;
    double withdraw;
    cout << "—ума ст€гу: "; cin >> sub;
    withdraw = money.get_sum() - sub;
    return withdraw;
}
double Account::Put()
{
    double add;
    double put;
    cout << "—ума начисленн€: "; cin >> add;
    put = money.get_sum() + add;
    return put;
}
const char* Account::SumToNumeral()
{
    const char* _centuries[11] = { "",
    "сто",
    "дв≥ст≥",
    "триста",
    "чотириста",
    "п'€тсот",
    "ш≥стсот",
    "с≥мсот",
    "в≥с≥мсот",
    "дев'€тсот",
    "тис€ча або б≥льше" };
    const char* _decades[10] = { "",
    "",
    "двадц€ть",
    "тридц€ть",
    "сорок",
    "п'€тдес€т",
    "ш≥стдес€т",
    "с≥мдес€т",
    "в≥с≥мдес€т",
    "дев'€носто" };
    const char* _digits[20] = { "",
    "один",
    "два",
    "три",
    "чотири",
    "п'€ть",
    "ш≥сть",
    "с≥м",
    "в≥с≥м",
    "дев'€ть",
    "дес€ть",
    "одинадц€ть",
    "дванадц€ть",
    "тринадц€ть",
    "чотирнадц€ть", "п'€тнадц€ть",
    "ш≥стнаднадц€ть",
    "с≥мнадц€ть",
    "в≥с≥мнадц€ть", "дев'€тнадц€ть" };

    if (money.get_sum() >= 1000)
        return _centuries[10];

    int sum = floor(money.get_sum());
    int cen = sum / 100;
    sum = sum % 100;
    int dec = sum / 10;
    int dig;
    if (dec == 0 || dec == 1)
        dig = sum % 20;
    else
        dig = sum % 10;

    int fractional = (money.get_sum() - floor(money.get_sum())) * pow(10, 2);
    int sumFrac = fractional;
    sumFrac = sumFrac % 100;
    int decFrac = sumFrac / 10;
    int digFrac;
    if (decFrac == 0 || decFrac == 1)
        digFrac = sumFrac % 20;
    else
        digFrac = sumFrac % 10;

    char s[100] = "";
    strcat_s(s, _centuries[cen]);
    strcat_s(s, " ");
    strcat_s(s, _decades[dec]);
    strcat_s(s, " ");
    strcat_s(s, _digits[dig]);
    strcat_s(s, " грн.");
    strcat_s(s, " ");
    strcat_s(s, _decades[decFrac]);
    strcat_s(s, " ");
    strcat_s(s, _digits[digFrac]);
    strcat_s(s, " коп.");
    return s;
}

void Account::Money::Set_1000(int value)
{
    if (value > 0)
        _1000 = value;
    else
        _1000 = 0;
}

void Account::Money::Set_500(int value)
{
    if (value > 0)
        _500 = value;
    else
        _500 = 0;
}

void Account::Money::Set_200(int value)
{
    if (value > 0)
        _200 = value;
    else
        _200 = 0;
}

void Account::Money::Set_100(int value)
{
    if (value > 0)
        _100 = value;
    else
        _100 = 0;
}

void Account::Money::Set_50(int value)
{
    if (value > 0)
        _50 = value;
    else
        _50 = 0;
}

void Account::Money::Set_20(int value)
{
    if (value > 0)
        _20 = value;
    else
        _20 = 0;
}

void Account::Money::Set_10(int value)
{
    if (value > 0)
        _10 = value;
    else
        _10 = 0;
}

void Account::Money::Set_5(int value)
{
    if (value > 0)
        _5 = value;
    else
        _5 = 0;
}

void Account::Money::Set_2(int value)
{
    if (value > 0)
        _2 = value;
    else
        _2 = 0;
}

void Account::Money::Set_1(int value)
{
    if (value > 0)
        _1 = value;
    else
        _1 = 0;
}

void Account::Money::Set_050(int value)
{
    if (value > 0)
        _050 = value;
    else
        _050 = 0;
}

void Account::Money::Set_025(int value)
{
    if (value > 0)
        _025 = value;
    else
        _025 = 0;
}

void Account::Money::Set_010(int value)
{
    if (value > 0)
        _010 = value;
    else
        _010 = 0;
}

void Account::Money::Set_005(int value)
{
    if (value > 0)
        _005 = value;
    else
        _005 = 0;
}

void Account::Money::Set_002(int value)
{
    if (value > 0)
        _002 = value;
    else
        _002 = 0;
}

void Account::Money::Set_001(int value)
{
    if (value > 0)
        _001 = value;
    else
        _001 = 0;
}
bool Account::Money::Init(int _1000, int _500, int _200, int _100, int _50, int _20, int _10, int _5, int _2, int _1, int _050, int _025, int _010, int _005, int _002, int _001)
{
    if (_1000 > 0)
    {
        Set_1000(_1000);
        return true;
    }

    if (_500 > 0)
    {
        Set_500(_500);
        return true;
    }

    if (_200 > 0)
    {
        Set_200(_200);
        return true;
    }

    if (_100 > 0)
    {
        Set_100(_100);
        return true;
    }

    if (_50 > 0)
    {
        Set_50(_50);
        return true;
    }

    if (_20 > 0)
    {
        Set_20(_20);
        return true;
    }

    if (_10 > 0)
    {
        Set_10(_10);
        return true;
    }

    if (_5 > 0)
    {
        Set_5(_5);
        return true;
    }

    if (_2 > 0)
    {
        Set_2(_2);
        return true;
    }

    if (_1 > 0)
    {
        Set_1(_1);
        return true;
    }

    if (_050 > 0)
    {
        Set_050(_050);
        return true;
    }

    if (_025 > 0)
    {
        Set_025(_025);
        return true;
    }

    if (_010 > 0)
    {
        Set_010(_010);
        return true;
    }

    if (_005 > 0)
    {
        Set_005(_005);
        return true;
    }

    if (_002 > 0)
    {
        Set_002(_002);
        return true;
    }

    if (_001 > 0)
    {
        Set_001(_001);
        return true;
    }
    else
        return false;
}
bool Account::Money::Init(double x)
{
    if (x < 0)
    {
        _1000 = 0;
        _500 = 0;
        _200 = 0;
        _100 = 0;
        _50 = 0;
        _20 = 0;
        _10 = 0;
        _5 = 0;
        _2 = 0;
        _1 = 0;
        _050 = 0;
        _025 = 0;
        _010 = 0;
        _005 = 0;
        _002 = 0;
        _001 = 0;

        return false;
    }
    _1000 = (int)(x / 1000.);
    x = x - _1000 * 1000.;
    _500 = (int)(x / 500.);
    x = x - _500 * 500.;
    _200 = (int)(x / 200.);
    x = x - _200 * 200.;
    _100 = (int)(x / 100.);
    x = x - _100 * 100.;
    _50 = (int)(x / 50.);
    x = x - _50 * 500.;
    _20 = (int)(x / 20.);
    x = x - _20 * 200.;
    _10 = (int)(x / 10.);
    x = x - _10 * 10.;
    _5 = (int)(x / 5.);
    x = x - _5 * 5.;
    _2 = (int)(x / 2.);
    x = x - _2 * 2.;
    _1 = (int)(x / 1.);
    x = x - _1 * 1.;
    _050 = (int)(x / 0.50);
    x = x - _050 * 0.50;
    _025 = (int)(x / 0.25);
    x = x - _025 * 0.25;
    _010 = (int)(x / 0.10);
    x = x - _010 * 0.10;
    _005 = (int)(x / 0.05);
    x = x - _005 * 0.05;
    _002 = (int)(x / 0.02);
    x = x - _002 * 0.02;
    _001 = (int)(x / 0.01);
    x = x - _001 * 0.01;

}
double Account::Money::get_sum() const
{
    return (_1000 * 1000. + _500 * 500. + _200 * 200. + _100 * 100. + _50 * 50. +
        _20 * 20. + _10 * 10. + _5 * 5. + _2 * 2. + _1 * 1. + _050 * 0.50 + _025 * 0.25 + _010 * 0.10 +
        _005 * 0.05 + _002 * 0.02 + _001 * 0.01);
}


void Account::Money::Read()
{
    do {
        cout << "\n—ума" << endl;
        cout << " 1000 - ? "; cin >> _1000;
        cout << " 500 - ? "; cin >> _500;
        cout << " 200 - ? "; cin >> _200;
        cout << " 100 - ? "; cin >> _100;
        cout << " 50 - ? "; cin >> _50;
        cout << " 20 - ? "; cin >> _20;
        cout << " 10 - ? "; cin >> _10;
        cout << " 5 - ? "; cin >> _5;
        cout << " 2 - ? "; cin >> _2;
        cout << " 1 - ? "; cin >> _1;
        cout << " 0.50 - ? "; cin >> _050;
        cout << " 0.25 - ? "; cin >> _025;
        cout << " 0.10 - ? "; cin >> _010;
        cout << " 0.05 - ? "; cin >> _005;
        cout << " 0.02 - ? "; cin >> _002;
        cout << " 0.01 - ? "; cin >> _001;
        cout << endl;
    } while (!Init(_1000, _500, _200, _100, _50, _20, _10, _5, _2, _1, _050, _025, _010, _005, _002, _001));


}
void Account::Money::Display() const
{
    cout << toString() << endl;
}

string Account::Money::toString() const
{
    stringstream sout;
    sout << "\n—ума" << endl;
    sout << " 1000 - " << _1000 * 1000. << endl;
    sout << " 500 - " << _500 * 500. << endl;
    sout << " 200 - " << _200 * 200. << endl;
    sout << " 100 - " << _100 * 100. << endl;
    sout << " 50 - " << _50 * 50. << endl;
    sout << " 20 - " << _20 * 20. << endl;
    sout << " 10 - " << _10 * 10. << endl;
    sout << " 5 - " << _5 * 5. << endl;
    sout << " 2 - " << _2 * 2. << endl;
    sout << " 1 - " << _1 * 1. << endl;
    sout << " 0.50 - " << _050 * 0.5 << endl;
    sout << " 0.25 - " << _025 * 0.25 << endl;
    sout << " 0.10 - " << _010 * 0.10 << endl;
    sout << " 0.05 - " << _005 * 0.05 << endl;
    sout << " 0.02 - " << _002 * 0.02 << endl;
    sout << " 0.01 - " << _001 * 0.01 << endl;
    sout << " «агалом - " << get_sum() << endl;
    sout << endl;

    return sout.str();
}

Account::Money Addition(const Account::Money& a, const Account::Money& b)
{
    Account::Money x;
    x._1000 = a._1000 + b._1000;
    x._500 = a._500 + b._500;
    x._200 = a._200 + b._200;
    x._100 = a._100 + b._100;
    x._50 = a._50 + b._50;
    x._20 = a._20 + b._20;
    x._10 = a._10 + b._10;
    x._5 = a._5 + b._5;
    x._2 = a._2 + b._2;
    x._1 = a._1 + b._1;
    x._050 = a._050 + b._050;
    x._025 = a._025 + b._025;
    x._010 = a._010 + b._010;
    x._005 = a._005 + b._005;
    x._002 = a._002 + b._002;
    x._001 = a._001 + b._001;

    return x;
}
Account::Money Subtraction(const Account::Money& a, const Account::Money& b)
{
    Account::Money x;
    x._1000 = a._1000 - b._1000;
    x._500 = a._500 - b._500;
    x._200 = a._200 - b._200;
    x._100 = a._100 - b._100;
    x._50 = a._50 - b._50;
    x._20 = a._20 - b._20;
    x._10 = a._10 - b._10;
    x._5 = a._5 - b._5;
    x._2 = a._2 - b._2;
    x._1 = a._1 - b._1;
    x._050 = a._050 - b._050;
    x._025 = a._025 - b._025;
    x._010 = a._010 - b._010;
    x._005 = a._005 - b._005;
    x._002 = a._002 - b._002;
    x._001 = a._001 - b._001;
    return x;
}

double Division(const Account::Money& a, const Account::Money& b)
{
    if (a.get_sum() > b.get_sum())
    {
        return a.get_sum() / b.get_sum();
    }
    if (a.get_sum() < b.get_sum())
    {
        return b.get_sum() / a.get_sum();
    }
}

Account::Money DivisionToFractionsNumber(const Account::Money& a, double div)
{
    double sum = a.get_sum();
    double res = sum / div;
    Account::Money x;
    x.Init(res);

    return x;
}
Account::Money MultToFractionsNumber(const Account::Money& a, double mult)
{
    double sum = a.get_sum();
    double res = sum * mult;
    Account::Money x;
    x.Init(res);

    return x;
}


bool More(const  Account::Money& a, const  Account::Money& b)
{
    return a.get_sum() > b.get_sum();
}
bool MoreEqual(const  Account::Money& a, const  Account::Money& b)
{
    return  a.get_sum() >= b.get_sum();
}
bool Less(const  Account::Money& a, const  Account::Money& b)
{
    return a.get_sum() < b.get_sum();
}
bool LessEqual(const  Account::Money& a, const  Account::Money& b)
{
    return a.get_sum() <= b.get_sum();
}
bool Equal(const  Account::Money& a, const  Account::Money& b)
{
    return a.get_sum() == b.get_sum();
}
bool NonEqual(const  Account::Money& a, const  Account::Money& b)
{
    return a.get_sum() != b.get_sum();
}

