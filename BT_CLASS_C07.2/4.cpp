/*
    su dung struct de bieu dien gio phut giay va tinh khong thoi gian giua 2 moc thoi gian nhap vao bnag giay. 
*/

#include <iostream>
#include <cmath>
using namespace std;
class Thoigian
{
private:
    int h, p, s;

public:
    Thoigian()
    {
        h = p = s = 0;
    }
    ~Thoigian()
    {
        h = p = s = 0;
    }
    void set()
    {
        cout << "Moi ban nhap gio: \n";
        cin >> this->h;
        cout << "Moi ban nhap phut: \n";
        cin >> this->p;
        cout << "Moi ban nhap giay: \n";
        cin >> this->s;
    }
    void get()
    {
        if (this->p < 10 && this->s < 10)
        {
            cout << this->h << "h0" << this->p << "p0" << this->s << "s\n";
        }
        else if (this->p < 10)
        {
            cout << this->h << "h0" << this->p << "p" << this->s << "s\n";
        }
        else if (this->s < 10)
        {
            cout << this->h << "h" << this->p << "p0" << this->s << "s\n";
        }
        else
            cout << this->h << "h" << this->p << "p" << this->s << "s\n";
    }
    int khoangtg(Thoigian a, Thoigian b)
    {
        return abs((a.h * 60 * 60 + a.p * 60 + a.s) - (b.h * 60 * 60 + b.p * 60 + b.s));
    }
};

int main()
{
    Thoigian a, b;
    cout << "Moi ban nhap moc thoi gian thu nhat: \n";
    a.set();
    cout << "Moi ban nhap moc thoi gian thu hai: \n";
    b.set();
    cout << "Duoi day la 2 mo thoi gian vua nhap:\n";
    a.get();
    b.get();
    cout << "Khoang giua 2 moc: " << a.khoangtg(a, b) << "s" << endl;
}