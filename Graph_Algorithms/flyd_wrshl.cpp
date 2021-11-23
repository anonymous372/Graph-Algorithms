#include<bits/stdc++.h>
using namespace std;

#define nxtl cout<<"\n";
//fors
#define loop(i,b) for(int i=0;i<b;i++)
#define rloop(i,b) for(int i=b;i>=0;i--) //from [b to 0]  	
#define arin(ar)  loop(i,sizeof(ar)/sizeof(ar[0])) cin>>ar[i];
#define show(ar)  loop(i,sizeof(ar)/sizeof(ar[0])) cout<<ar[i]<<" ";
#define For(i,a,b) for (int i = a;(a<b)?i<b:i>=b;(a<b)?i++:i--)//from [a to b)or[b to a]


//Vector
#define vec(v) vector<int> v
#define pb(a) push_back(a)
#define pii pair<int,int>
#define pbp(a,b) push_back({a,b})
#define pp(a,b) push({a,b})
#define all(a) (a.begin(),a.end()) 
#define fs first
#define sc second

#define inf 1000
// Floyd Warshall is an All Pair Shortest Path Algorithm


main(){
	int n;
	cout<<"Enter # of nodes : ";
	cin>>n;
	vector<pii> adj[n];
	// vector<int> prev(n,0);
	// prev[0]=0;
	//Inputting the weighted graph 
	cout<<"Enter node weight pairs for each node :\n";
	loop(i,n){
		cout<<i+1<<" : ";
		int u,w;
		while(1){
			cin>>u;
			if(!u) break;
			cin>>w;
			if(u>n||w<0) continue;
			u--;
			adj[i].pbp(u,w);
		}
	}
	vector<vector<int>> mt;
	mt.resize(n,vector<int>(n,inf));
	loop(i,n){
		for(auto it:adj[i]){
			mt[i][it.fs]=it.sc;
		}
	}
	// The Matrix
	loop(i,n){ for(auto it:mt[i]) cout<<it<<" "; cout<<"\n";}

	// Lets Begin The Algorithm
	//make a dp array n x n
	int dp[n][n];
	// initialize it with values
	loop(i,n) loop(j,n) dp[i][j] = mt[i][j];
	// shortest path from node a->a is of 0 length
	loop(i,n) dp[i][i]=0;

	loop(k,n){
		loop(i,n){
			loop(j,n){
				int a=dp[i][j],
					b=dp[i][k],
					c=dp[k][j];
				//if the shortest pathb from i->j is through k then crrct the dp array
				//scnd if condition is there bcz inf + inf != inf so its an alt.
				if(a > b + c and b!=inf and c!=inf)
					dp[i][j]=b+c;
			}
		}
	}
	cout<<"\n All Pair Shortest Path Array\n";
	loop(i,n){
		cout<<i+1<<" : ";
		loop(j,n){
			cout<<dp[i][j]<<"   ";
		}
		cout<<"\n";
	}
	// Sample Input
	// Enter # of nodes : 4
	// Enter node weight pairs for each node :
	// 1 : 2 4 3 2 0
	// 2 : 1 3 4 3 0
	// 3 : 1 2 2 1  4 5 0
	// 4 : 3 4 0
}