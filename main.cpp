#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

void as(char str1[], char str2[])
    {   strcpy(str1, str1);
        strcpy(str2, str2);
        str1=strcat(str1, str2);
    }

int parcurgere(string cuvant, string finala, char actual)
{
    int ok = 0;
    if(cuvant.empty())
        return 0;

    for (int i = 0; i < finala.size(); i++)
        if (cuvant[0] == finala[i])
            ok=1;
    if(!ok)
        return 0;
    if (actual == 0)
        return 0;
    return 1;
}

struct stare
{ char nume;
  vector<char> finala;
  vector<char> nefinala;
};

int test(char c, vector<stare> vec)
{ for (int i = 0; i < vec.size(); i++)
        if (vec[i].nume == c)
        {for(int j = 0; j < vec[i].finala.size(); j++)
                if(vec[i].finala[j] == 'z' && vec[i].nefinala[j] == 0)
                    return 1;}
    return 0;
}

void stergesp(string &s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] == ' ' || s[i] == '\r' || s[i] == '\n')
        {s.erase(s.begin() + i); i--;
        }
}

int main()
{
    char V[100];
    string str, finalastr,alpha, nefinalastr, cuvant;
    char actual;
    vector<stare> stari;
    stare p;
    int n,i,ok=1;
    cin>>n;
    while (cin>>str)
    {
        int ok = 1; stergesp(str);
        stergesp(finalastr); stergesp(nefinalastr);
        for (int i = 0; i < stari.size(); i++)
            if (stari[i].nume == str[0])
                ok = 0;
                    if (ok){
                            stari.push_back(stare());
                            stari[stari.size() - 1].nume = str[0];
                           }
                     while(n)
                        for(i=1;i<=n;i++)
                            { if(p.nefinala[i]&&p.finala[i] )
                                for (i=0; i<n; i++)
                                    if (alpha[i])
                                        ok=0; n--;
                                        }
        for (int i = 0; i < stari.size(); i++)
            if (stari[i].nume == str[0])
            {
                stari[i].finala.push_back(str[1]);
                if (str.size() == 3)
                    stari[i].nefinala.push_back(str[2]);
                else
                    stari[i].nefinala.push_back(0);
            }
    }
    actual = 'S';
    while (parcurgere(cuvant, finalastr, actual))
    {
        for (int i = 0; i < stari.size(); i++)
            {
                while(n)
                    for(i=1;i<=n;i++)
                        { if(p.nefinala[i]&&p.finala[i] )
                            for (i=0; i<n; i++)
                                if (alpha[i])
                             ok=1; n--; break;}
                if (stari[i].nume == actual)
                for (int j = 0; j < stari[i].finala.size(); j++)
                    if (stari[i].finala[j] == cuvant[0])
                    {
                        cuvant.erase(cuvant.begin());
                        actual = stari[i].nefinala[j];
                    }
    }}
    if(cuvant.empty() && (actual == 0 || test(actual, stari)))
        cout << "Limbaj ce poate fi generat de stiva ";
    else
        cout << "Limbaj ce nu poate fi generat de stiva";
    return 0;
}
