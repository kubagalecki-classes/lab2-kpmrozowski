#include <cstdio>
#include <iostream>
using namespace std;

class Wektor
{
private:
    double* we{NULL}; // double* we = NULL;

public:
    int dlugosc;
    int pojemnosc;
    Wektor(int idlugosc) : dlugosc{idlugosc}, pojemnosc{idlugosc}, we{new double[idlugosc]}
    {
        puts("default constructor");
        cout << "we(" << dlugosc << ")\n";
        for (int i = 0; i < dlugosc; i++) {
            we[i] = i + 1;
        }
    }
    Wektor(const Wektor& iw)
    {
        puts("copy constructor");
        cout << "we(" << iw.pojemnosc << ")\n";
        for (int i = 0; i < iw.pojemnosc; i++) {
            we[i] = iw.we[i];
        }
    };
    ~Wektor()
    {
        cout << "del\n";
        delete[] we;
    }
    int  getDlugosc() { return dlugosc; }
    int  getPojemnosc() { return pojemnosc; }
    void print()
    {
        for (int i = 0; i < dlugosc; i++) {
            cout << "we[" << i << "]=" << we[i] << " ";
        }
        cout << "\n";
    }
    void zmienDlugosc(int nowaDlugosc)
    {
        if (nowaDlugosc > pojemnosc) {
            double* tmp = we;
            we          = new double[nowaDlugosc];
            for (int i = 0; i < dlugosc; i++) {
                we[i] = tmp[i];
            }
            delete[] tmp;
            for (int i = dlugosc; i < nowaDlugosc; i++) {
                we[i] = 0;
            }
            dlugosc   = nowaDlugosc;
            pojemnosc = nowaDlugosc;
        }
        else {
            for (int i = nowaDlugosc; i < pojemnosc; i++) {
                we[i] = 0;
            }
            dlugosc = nowaDlugosc;
        }
    }
    double& operator[](const int index)
    {
        zmienDlugosc(index + 1);
        return we[index];
    }
};

int main()
{

    Wektor w(5);
    w.print();
    w[7] = 42.;
    w.print();
    double& a = w[7];
    a++;
    w.print();

    Wektor wc{w};
    wc.print();
    wc[7] = 42.;
    wc.print();
    double& b = wc[7];
    b++;
    wc.print();
    return 0;
}