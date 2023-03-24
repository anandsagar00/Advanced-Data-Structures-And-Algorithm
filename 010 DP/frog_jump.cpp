// Video : https://youtu.be/EgG3jsGoPvQ?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY

// Problem Link 1 : https://atcoder.jp/contests/dp/tasks/dp_a

// Problem Link 2 : https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <unordered_map>
#include <set>
#include <map>
#include <unordered_set>
#include <string>
#include <limits.h>
#include <cstdlib>
using namespace std;
#define ll long long int
const int mod = 1e9 + 7;

ll minCost(int i, vector<ll> &dp, vector<int> &heights)
{
    if (i < 0)
        return INT_MAX;
    if (i == 0)
        return 0;
    else if (dp[i] != -1)
        return dp[i];
    else
    {
        // What is the cost till now when I take 1 step and when I take 2 steps
        ll cost_steps1 = minCost(i - 1, dp, heights);
        ll cost_steps2 = minCost(i - 2, dp, heights);

        return dp[i] = min<long>(cost_steps1 + abs(heights[i] - heights[i - 1]), cost_steps2 + abs(heights[i] - heights[i - 2]));
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> heights(n, -1);
    vector<ll> dp(n + 1, -1);

    for (int i = 0; i < n; i++)
        cin >> heights[i];

    cout << minCost(n - 1, dp, heights);
}