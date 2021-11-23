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

void dfs(vector<int> v[],vector<int>& order,int cur,bool vst[]){
	vst[cur]=true;
	for(auto it : v[cur]){
		if(!vst[it])
			dfs(v,order,it,vst);
	}
	order.pb(cur);
}

main(){
	int n;
	cout<<"Enter # of nodes : ";
	cin>>n;
	vector<int> adj[n];
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

	vector<int> order;
	bool vst[n]={false};
	for(int i=0;i<n;i++){
		if(!vst[i])
		dfs(adj,order,i,vst);
	}
	cout<<"\nOrder : ";
	for(int i=n-1;i>=0;i--){
		cout<<order[i]+1<<" ";
	}
}