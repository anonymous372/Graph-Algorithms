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


// DJKSTRA'S ALGORITHM
vector<int> djkstra(vector<pii> v[],int cur,int n,vector<int> &prev){
	priority_queue <pii, vector<pii>, greater<pii>> q;
	vector<int> sp(n,1e3);
	sp[cur]=0;
	q.pp(cur,0);
	
	while(!q.empty()){
		pii edge = q.top();

		q.pop();
		cur=edge.sc;
		for(auto it : v[cur]){
			if(it.sc+sp[cur] < sp[it.fs]) {
				sp[it.fs] = it.sc+sp[cur];	
				prev[it.fs] = cur;
			}
			q.pp(it.sc,it.fs);
		}
	}
	return sp;
}

main(){
	int n;
	cout<<"Enter # of nodes : ";
	cin>>n;
	vector<pii> adj[n];
	vector<int> prev(n,0);
	prev[0]=0;
	//Inputting the weighted graph 
	cout<<"Enter node weight pairs for each node :\n";
	loop(i,n){
		cout<<i+1<<" : ";
		int u,w;
		while(1){
			cin>>u>>w;
			if(!u) break;
			if(u>n||w<0) continue;
			u--;
			adj[i].pbp(u,w);
		}
	}
	cout<<"\nThe graph looks like :\n";
	loop(i,n){
		cout<<i+1<<" : ";
		for(auto it:adj[i])
			cout<<"{"<<it.fs+1<<","<<it.sc<<"},";
		cout<<"\n";
	}

	vector<int> sp = djkstra(adj,0,n,prev);
	
	cout<<"\nShortest path from node 0 to all other nodes is  :\n";
	int cnt=1;
	for(auto it : sp){
		cout<<cnt<<" : "<<it<<" ,Path : "<<cnt<<"<-";
		
		int i=cnt-1;
		cnt++;
		while(i){
			cout<<prev[i]+1<<"<-";
			i=prev[i];
		}
		cout<<"\b\b";
		nxtl;
	}
	// sample graph with n=5
	// adj[0].pbp(1,4);
	// adj[0].pbp(2,2);
	// adj[1].pbp(3,3);
	// adj[2].pbp(1,1);
	// adj[2].pbp(4,2);
	// adj[3].pbp(4,1);
}