#include <iostream>
#include <cmath>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

float del(int a, int b)
{
    return (float)a/(float)b;
}

double stepen(int a, int b)
{
    return pow(a, b);
}

void calc(int a, int b, void *op)
{
   
    if (op == &add)
        cout << add(a,b) << endl;
    if (op == &sub)
        cout << sub(a,b) << endl;
    if (op == &del)
        cout << del(a,b) << endl;
    if (op == &stepen)
        cout << stepen(a,b) << endl;
   
}


int main() {

    int x = (int)'H';
    int y = (int)'G';



    calc(x, y,  (void*)sub);

    calc(x, y, (void*)add);

    calc(x, y, (void*)del);
    calc(x, y, (void*)stepen);
    
    return 0;
}