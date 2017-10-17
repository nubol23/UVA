#include<bits/stdc++.h>
using namespace std;

int winds[15][1005];
int memo[15][1005];

int solve(int alt, int dist, int X){
	if(alt > 9 || alt < 0 || (dist == X && alt > 0)) return (1<<30);
	if(dist == X && alt == 0) return 0;

	if(memo[alt][dist] != -1) return memo[alt][dist];
	
	return (memo[alt][dist] = min(60 - winds[alt][dist] + solve(alt+1,dist+1,X),
								  min(30 - winds[alt][dist] + solve(alt,dist+1,X),
									  20 - winds[alt][dist] + solve(alt-1,dist+1,X))));
}

int main()
{   ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int X;
		cin>>X;
		X /= 100;
		
		for(int alt = 9; alt >= 0; alt--){
			for(int dist = 0; dist < X; dist++){
				cin>>winds[alt][dist];
			}
		}

		memset(memo, -1, sizeof(memo));

		cout<<solve(0,0,X)<<"\n\n";
	}
	return 0;
}
