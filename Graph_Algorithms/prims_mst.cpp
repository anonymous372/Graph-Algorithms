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

vector<bool> vst;
vector<vector<pii>> tree;
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;

void dfs(vector<pii> v[],int at){
	vst[at]=true;
	// cout<<"* ";
	for(auto to : v[at]){
		// cout<<"# ";
		if(!vst[to.fs]){
			// cout<<"& ";
			pq.push(make_tuple(to.sc,at,to.fs));
			// cout<<"OK  |";
		}
	}
	int nxt,wt,from;

	tie(wt,from,nxt)=pq.top();
	
	if(!vst[nxt])
	tree[from].pbp(nxt,wt);

	pq.pop();

	if(pq.size())
	dfs(v,nxt);
}

void prims_mst(vector<pii> v[],int n){
	dfs(v,0);
	// The Minimum Spanning Tree formed is
	cout<<"\nMinimum Spanning Tree\n";
	int sum=0;
	loop(i,n){
		cout<<i<<" : ";
		for(auto it : tree[i]){
			cout<<"{"<<it.fs<<","<<it.sc<<"} ";
			sum+=it.sc;
		}
		nxtl;
	}
	cout<<"\n\nSum : "<<sum;
}

main(){
	int n;
	cout<<"Enter # of nodes : ";
	cin>>n;
	vst.resize(n,false);
	tree.resize(n);
	vector<pii> adj[n];

	//Inputting the weighted graph 
	cout<<"Enter node connected each node:\n";
	loop(i,n){
		cout<<i<<" : ";
		int u,wt;
		while(1){
			cin>>u>>wt;
			if(!u) break;
			if(u>n) continue;
			// u--;
			adj[i].pbp(u,wt);
			adj[u].pbp(i,wt);
		}
	}
	// Now we have a directed graph
	// Displaying the graph
	cout<<"\nGRAPH\n";
	loop(i,n){
		cout<<i<<" : ";
		for(auto it: adj[i]){
			cout<<"{"<<it.fs<<","<<it.sc<<"} ";
		}
		cout<<"\n";
	}
	prims_mst(adj,n);

	// Sample Graph
	// 1 10 2 1 3 4 0 0
	// 2 3 4 0 0 0
	// 5 8 3 2  0 0
	// 5 2 6 7 0 0
	// 5 1 7 8 0 0
	// 7 9 6 6 0 0
	// 7 12 0 0
	// 0 0
}