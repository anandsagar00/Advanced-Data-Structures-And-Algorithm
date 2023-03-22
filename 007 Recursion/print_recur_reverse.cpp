// Description : https://takeuforward.org/recursion/print-n-to-1-using-recursion/

// print n to 1 using recursion

#include<iostream>
using namespace std;
#define ll long long int
const int mod=1e9+7;

void fun(int n)
{
    if(n<=0)
    return ;
    cout<<n<<" ";
    fun(n-1);
}

int main()
{
    fun(12);
}