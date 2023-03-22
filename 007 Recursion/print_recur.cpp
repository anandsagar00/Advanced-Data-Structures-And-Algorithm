//Description : https://takeuforward.org/recursion/print-1-to-n-using-recursion/

//Print 1 to n using recursion

#include<iostream>
using namespace std;
#define ll long long int
const int mod=1e9+7;

void fun(int n)
{
    if(n<=0)
    return;

    fun(n-1);
    cout<<n<<" ";

}

int main()
{
    fun(10);
}