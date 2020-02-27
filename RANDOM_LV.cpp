/*
    Lay radom cac so
*/

#include <iostream>
#include <random>
using namespace std;
int main()
{
    int a, b;
    cout << "Moi ban nhap khoang can radom tu [a,b]:  ";
    cin >> a >> b;

    // khai bao random
    random_device rd;
    mt19937 aa(rd());
    uniform_int_distribution<int> uni(a, b);

    cout << "Sau day la lan luot cac so duoc random\n";
    int s[b - a];
    for (int i = 0; i < b - a;)
    {
        getchar();
    he:
        s[i] = uni(aa);
        int dem = 0;
        for (int j = 0; j < i; j++)
        {
            if (s[i] == s[j])
            {
                dem++;
                break;
            }
        }
        if (dem == 0)
        {
            cout << "\t" << s[i];
            i++;
            cout << "  ";
            continue;
        }
        else
            goto he;
    }
}