/*
There is a company named James Peterson & Co. The company has ‘n’ employees. The employees have skills from 0 to n-1. 
All the employees have distinct skills. The manager of James Peterson & Co. wants to sort the employees on the basis of their skills in ascending order. 
He is only allowed to swap two employees which are adjacent to each other. He is given the skills of employees in an array of size ‘n’.
He can swap the skills as long as the absolute difference between their skills is 1. 
You need to help the manager out and tell whether it is possible to sort the skills of employees or not.
Input Format:

First Line will have an integer ‘t’ denoting the no. of test cases.
First line of each test case contains an integer ‘n’ denoting the no. of employees in the company.
Second line of each test case contains ‘n’ distinct integers in the range [0, n-1].

Output Format:

For each test case, print “Yes” if it is possible to sort the skills otherwise “No”.

Constraints:

1 <= t <= 10
1 <= n <= 10^5

Sample Input:

2
4
1 0 3 2
3
2 1 0

Sample Output:

Yes
No

Explanation:

In first T.C., [1, 0, 3, 2] -> [0, 1, 3, 2] -> [0, 1, 2, 3]
In second T.C., [2, 1, 0] -> [1, 2, 0]  OR  [2, 1, 0] -> [2, 0, 1] So, it is impossible to sort.
*/
#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
int n;
vector<int> a;
void swap(int &x,int &y){
	if(&x != &y){
		x^=y;
		y^=x;
		x^=y;
	}
}
void solve(){
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n-1;i++){
		if(a[i+1]==a[i]-1){
			swap(a[i],a[i+1]);
		}
	}
	for(int i=0;i<n-1;i++){
		if(a[i+1]<a[i]){
			cout<<"No\n";
			return;
		}
	}
	cout<<"Yes\n";
}
int main(){
	IOS;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
