//Description : https://takeuforward.org/recursion/print-1-to-n-using-recursion/

//Print 1 to n using recursion

#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<utility>
#include<unordered_map>
#include<set>
#include<map>
#include<unordered_set>
#include<string>
#include<limits.h>
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