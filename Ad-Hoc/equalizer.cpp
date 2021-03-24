/*
https://codeforces.com/problemset/problem/1037/C
*/
#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
string t,s;
int n;
void solve(){
	cin>>n;
	cin>>s>>t;
	int cost=0;
	for(int i=0;i<n;i++){
		if(s[i]!=t[i]){
			if(s[i+1]!=s[i] && s[i+1]!=t[i+1]){  //swap
				i++;
			}
			cost++;
		}
	}
	cout<<cost<<'\n';
}
int main(){
	IOS;
	solve();
	return 0;
}
