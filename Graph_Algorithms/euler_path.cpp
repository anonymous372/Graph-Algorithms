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

//
vector<int> in,out;
vector<bool> vst;
vector<int> path;

void dfs(vector<int> v[],int at){
	while(out[at]){
		int nxt=v[at][--out[at]];
		dfs(v,nxt);
	}
	path.pb(at);
}

void euler_path(vector<int> v[],int n){
	
	loop(i,n){
		for(auto it : v[i]){
			out[i]++;
			in[it]++;
		}
	}
	bool flg=true;
	cout<<"\nIn/Out Degrees\n";
	loop(i,n){
		cout<<i+1<<" : "<<in[i]<<" | "<<out[i]<<"\n";
		if(abs(in[i]-out[i])>1) flg=false;
	}
	// Finding the starting node
	int start=0;
	loop(i,n){
		if(out[i]-in[i]==1) {start=i; break;}
		if(out[i]>0) start=i;
	}
	// cout<<"\n"<<start<<"\n";
	nxtl;
	if(flg){
		dfs(v,start);
		for(auto it: path) cout<<it+1<<" ";
	}
}

main(){
	int n;
	cout<<"Enter # of nodes : ";
	cin>>n;
	vst.resize(n,false);
	in.resize(n,0);
	out.resize(n,0);
	vector<int> adj[n];

	//Inputting the weighted graph 
	cout<<"Enter node connected each node:\n";
	loop(i,n){
		cout<<i+1<<" : ";
		int u;
		while(1){
			cin>>u;
			if(!u) break;
			if(u>n) continue;
			u--;
			adj[i].pb(u);
		}
	}
	// Now we have a directed graph
	// Displaying the graph
	cout<<"\nGRAPH\n";
	loop(i,n){
		cout<<i+1<<" : ";
		for(auto it: adj[i]){
			cout<<it+1<<" ";
		}
		cout<<"\n";
	}
	euler_path(adj,n);

	//Sample Graph 
	// 2 3 0
	// 2 4 4 0
	// 1 2 5 0
	// 3 6 0
	// 6 0
	// 3 0
	// ANS: 1 3 5 6 3 2 4 3 1 2 2 4 6
}