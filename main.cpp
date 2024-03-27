#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

ifstream cin("dbx.in");
ofstream cout("dbx.out");

// a*x^2+b*x+c
char formula[1024];


double f(double x){
    double ans = 0;
    double a, pwr = 0;
    bool op = true;
    bool xFound = false;
    for(int i = 0; i < strlen(formula);){
        if(formula[i] == '-') {
            op = false;
            i++;
        }
        else if(formula[i] == '+'){
            op = true;
            i++;
        }
        else if(formula[i] == 'x'){
            xFound = true;
            i++;
        }
        else if(isalnum(formula[i])){
            while(isalnum(formula[i])){
                a = a*10 + ((int) formula[i] - 48);
                i++;
            }
            //trecem de *
            i++;
        }
        else if(formula[i] == '^'){
            i++;
            while(isalnum(formula[i])){
                pwr = pwr*10 + ((int) formula[i] - 48);
                i++;
            }
        }

    }

    ans = a * pow(x, pwr);
    if(!op) ans = -1 * ans;

    return ans;

}

int main()
{
    cin.getline(formula,1024);
    cout<<f(1)<<endl;
    cout<<f(2)<<endl;
    cout<<f(3)<<endl;
    return 0;
}
