#include <iostream>
#include "lab1.h"
using namespace std;

namespace PROG_1 {
    int getNum(int& m)
    {
        cin >> m;
        while (!cin.good())
            return 1;
        return 0;
    }

    Int** create(Int** mas, int m, int*n)
    {
        int Er;
        cout << "Enter number of cols --> ";
        Er = getNum(*n); // number of cols
        if (Er)
        {
            return nullptr;
        }
        try {
            mas = new Int * [m];
        }
        catch (std::bad_alloc & ba) {
            std::cout << "------ too many rows in matrix: " << ba.what() << std::endl;
            delete[] mas;
            return nullptr;
        }
        int h = 1;
        int key;
        int ii;
        int jj;
        int* str = new int[*n];
        for (int i = 0; i < m; i++) { mas[i] = new Int; mas[i][0].n = 0; }
        while (h) {
            for (int i = 0; i < *n; i++) { str[i] = 0; }
            cout << "---------------------------" << endl;
            cout << "Enter your row number --> ";
            Er = getNum(ii);
            if (Er) return nullptr;
            if ((ii > m) || (ii < 1)) {
                cout << "Incorrect row number " << endl;
                continue;
            }
            jj = 1;
            int k = 0;
            while (jj) {
                cout << "------------" << endl;
                cout << "Enter your col number(if you want to exit, enter 0) --> ";
                Er = getNum(jj);
                if (Er) return nullptr;
                if (jj == 0)
                    break;
                if ((jj > *n) || (jj < 0)) {
                    cout << "Incorrect col number " << endl;
                    continue;
                }
                cout << "Enter your key --> ";
                Er = getNum(key);
                if (Er) return nullptr;
                if (key == 0) {
                    cout << "Incorrect key" << endl;
                    continue;
                }
                if (str[jj - 1] == 0) k++;
                str[jj - 1] = key;
            }
            for (int i = 0; i < mas[ii - 1][0].n; i++) { //здесь мы дополняем массив str уже существующими элементами cтроки mas[i]
                if (str[mas[ii - 1][i].col] == 0)
                {
                    str[mas[ii - 1][i].col] = mas[ii - 1][i].key;
                    k++;
                }
            }
            delete[] mas[ii - 1];
            mas[ii - 1] = new Int[k];
            mas[ii - 1][0].n = k;
            //mas[ii-1][jj-1] = key;
            int nn = 0;
            for (int j = 0; j < *n; j++)
            {
                if (str[j] != 0)
                {
                    mas[ii - 1][nn].key = str[j];
                    mas[ii - 1][nn].col = j;
                    mas[ii - 1][nn].unique = true;
                    nn++;
                }
                if (nn > k) break;
            }
            cout << "if you want to exit, enter 0; If not, enter 1, or another to continue --> ";
            getNum(h);
        }
        delete[] str;
        return mas;
    }

    int* createMas(Int** mas, int m)
    {
        int n = 0;
        int* a = new int[m];
        for (int i = 0; i < m; i++)
        {
            if (mas[i][0].n == 0) {
                a[n] = 1;
                n++;
                continue;
            }
            int count = 0 ;
            for (int j = 0, k = j + 1; j < mas[i][0].n; ++j)
            {
                if (mas[i][j].unique)
                {
                    count++;
                    for (; k < mas[i][0].n; ++k)
                        if (mas[i][j].key == mas[i][k].key)  mas[i][k].unique = false;
                }
            }
            //cout << "Count = " << count << endl;
            if (count) {
                a[n] = count + 1; 
                ++n;
            }
        }
        return a;
    }

    void errase(Int** mas, int m) {
        for (int i = 0; i < m; i++)
            delete[] mas[i];
        delete[] mas;
    }

    void output(Int** mas, int m, int n)
    {
        cout << "Output process:" << endl;
        for (int i = 0; i < m; i++) {
            cout << i + 1 << ". ";
            int g = mas[i][0].n;
            for (int j = 0; j < mas[i][0].n; j++) {
                //cout << "[i;j] = [" << i << ";" << j <<"] ";
                cout << mas[i][j].key << '(' << mas[i][j].col + 1 << ')' << '|';
            }
            cout << endl;
        }
        cout << "\nFirst output:" << endl;
        for (int i = 0; i < m; i++, cout << endl) {
            //cout << i + 1 << ". ";
            int t = 0;
            int ch;
            if (mas[i][0].n == 0) ch = n;
            else ch = mas[i][t].col;
            for (int j = 0; j < n; j++)
            {
                //cout << "CH = " << ch << endl;
                if (j != ch)
                    cout << "0[" << i + 1 << ";" << j + 1 << "]| ";
                else
                {
                    cout << mas[i][t].key << '[' << i + 1 <<
                        ";" << mas[i][t].col + 1 << "]| ";
                    ++t;
                    if (t >= mas[i][0].n) t = n - 1;
                    if (mas[i][0].n == 0) ch = n;
                    else ch = mas[i][t].col;
                }
            }
                
        }
    }

    void output(int* mas, int n)
    {
        cout << "\nSecond output:\n";
        for (int i = 0; i < n; i++)
        {
            cout << mas[i] << "[" << i + 1 << "]|";
            if ((i+1) % 10 == 0) cout << endl;
        }
        cout << endl;
    }
}