/*
https://www.codechef.com/problems/AX06
*/
#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
int grid[9][9];
bool findEmptyPos(int &r,int &c){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(grid[i][j]==0){
				r=i;
				c=j;
				return true;
			}
		}
	}
	return false;
}
bool isSafeInRow(int r,int n){
	for(int i=0;i<9;i++){
		if(grid[r][i]==n){
			return false;
		}
	}
	return true;
}
bool isSafeInCol(int c,int n){
	for(int i=0;i<9;i++){
		if(grid[i][c]==n) return false;
	}
	return true;
}
bool isSafeInBox(int r,int c,int n){
	int rowFact=r-(r%3);
	int colFact=c-(c%3);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(grid[i+rowFact][j+colFact]==n){
				return false;
			}
		}
	}
	return true;
}
bool isSafe(int r,int c,int n){
	return isSafeInRow(r,n) && isSafeInCol(c,n) && isSafeInBox(r,c,n);
}
bool solve(){
	int r,c;
	if(!findEmptyPos(r,c)) return true;
	for(int i=1;i<=9;i++){
		if(isSafe(r,c,i)){
			grid[r][c]=i;
			if(solve()) return true;
			grid[r][c]=0;
		}
	}
	return false;
}
void print(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<grid[i][j];
		}
		cout<<'\n';
	}
}
int main(){
	IOS;
	string s;
	for(int i=0;i<9;i++){
		cin>>s;
		for(int j=0;j<9;j++){
			grid[i][j]=s[j]-'0';
		}
	}
	solve();
	print();
	return 0;
}
