#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream f("cin.txt");

class automat;

class stare
{
    friend class automat;
    char tranz[20];
    bool finax;
};

class automat
{

    stare A[15][15];
    int n;

public:

    void read()
    {
        f>>n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                f >> A[i][j].tranz;
                A[i][j].finax=false;
            }
        int x;
        cout<<"nr stari finale:";
        cin>>x;
        cout<<"starile finale:";
        for(int i=0; i<x; i++)
        {
            int fin;
            cin>>fin;
            A[fin][fin].finax=true;
        }
    }

    bool cuvant()
    {
        char cuv[100];
        f>>cuv;
        int j=0;
        for(int k=0; k<(int)strlen(cuv); k++)
        {
            int ok=1;
            for(int i=0; i<n && ok; i++)
            {
                //cout<<strchr(A[j][i].tranz,cuv[k])<<' ';
                if(strchr(A[j][i].tranz,cuv[k]))
                {
                    j=i;
                    //cout<<j<<' ';
                    ok=0;
                }
            }
        }
        cout<<cuv;
        return A[j][j].finax;
    }
};

int main()
{
    automat x;
    x.read();
    while(!f.eof())
    if(x.cuvant())
        cout<<" apartine limbajului\n";
    else
        cout<<" nu apartine limbajului\n";
    return 0;
}

