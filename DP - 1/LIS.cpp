// Longest Increasing Sequence
#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
int n;
vector<int> v,dp;
void solve(){
    cin>>n;
    v.resize(n);
    dp.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int best=0;
    dp[0]=1;
    for(int i=1;i<n;i++){
        dp[i]=1;
        for(int j=i-1;j>=0;j--){
            if(v[j]<=v[i]) dp[i]=max(dp[i],dp[j]+1);
        }
        best=max(best,dp[i]);
    }
    cout<<best<<'\n';
}
int main(){
    IOS;
    solve();
    return 0;
}
