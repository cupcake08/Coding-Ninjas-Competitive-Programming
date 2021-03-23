/*
Taj Mahal is one of the seven wonders of the world. Aahad loves to travel places and wants to visit Taj Mahal.
He visited Agra to view Taj Mahal. There is a ticketing system at Taj Mahal. 
There are total ‘n’ windows which provide the tickets to get entry into Taj Mahal. 
There are ‘Ai’ people already present at each window to get the tickets. Each window gives ticket to one person in one minute.
Initially, Aahad stands in front of the first window. After each minute, if he didn’t get the ticket, he moves on to the next window to get the ticket. I
f he is at window 1, he will move to 2. If at 2nd, he will move to 3rd. If he is at last window, he will move to 1st again and so on. 
Find the window number at which he will get the ticket.
Input Format:

First line contains a single integer ‘n’ denoting the no. of windows.
Next line contains ‘n’ space separated integers denoting the no. of people already standing in front of the ith window. (1 <= i <= n)

Output Format:

Print a single integer denoting the window number that Aahad will get ticket from.

Constraints:

1 <= n <= 10^5
1 <= Ai <= 10^9

Sample Input:

4
2 3 2 0

Sample Output:

3

Explanation:

Aahad at Window 1: [2, 3, 2, 0]
Aahad at Window 2: [1, 2, 1, 0]
Aahad at Window 3: [0, 1, 0, 0]
So, when Aahad is at window 3, he got zero people before him. Hence, he will get the ticket at window 3.
*/
#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

void solve(){
	int n;
	cin>>n;
	long *a=new long[n+1];
	long *b=new long[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]-=i-1;
		if(a[i]<0) a[i]=0;
		long t=a[i]/n;
		if(a[i]%n!=0) t+=1;
		b[i]=(n*t)+i;
	}
	long an=INT_MAX,rv=-1;
	for(int i=1;i<=n;i++){
		if(b[i]<an){
			an=b[i];
			rv=i;
		}
	}
    delete[] a;
    delete [] b;
	cout<<rv<<"\n";
}
int main(){
	IOS;
	solve();
	return 0;
}
