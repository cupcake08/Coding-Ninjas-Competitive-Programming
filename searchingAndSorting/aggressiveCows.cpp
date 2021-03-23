#include <bits/stdc++.h>

using namespace std;
bool check(int c,long long *pos,int n,long long dist){
        int count=1;
        long long last_pos=pos[0];
        for(int i=1;i<n;i++){
                if(pos[i]-last_pos >= dist){
                        last_pos=pos[i];
                        count++;
                }
                if(count==c){
                        return true;
                }
        }
        return false;
}
int main(){
        int t;
        cin>>t;
        while(t--){
                int n,c;
                cin>>n>>c;
                long long pos[n];
                for(int i=0;i<n;i++) cin>>pos[i];
                sort(pos,pos+n);
                long long start=0;
                long long end=pos[n-1]-pos[0];
                long long ans=-1;
                while(start <= end){
                        long long mid=start+(end-start)/2;
                        if(check(c,pos,n,mid)){
                                ans=mid;
                                start=mid+1;
                        }else{
                                end=mid-1;
                        }
                }
                cout<<ans<<endl;
        }
}

