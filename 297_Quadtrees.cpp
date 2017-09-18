#include<bits/stdc++.h>
using namespace std;

unordered_map<int,char> t1;
unordered_map<int,char> t2;

int nivel(int n){
	if((1<=n)&&(n<=1)) return 0;
	if((4<=n)&&(n<=(2*4))) return 1;
	if((16<=n)&&(n<=(2*16))) return 2;
	if((64<=n)&&(n<=(2*64))) return 3;
	if((256<=n)&&(n<=(2*256))) return 4;
	if((1024<=n)&&(n<=(2*1024))) return 5;
}
int val_nodo_nivel(int nivel){
	if(nivel == 0) return 1024;
	if(nivel == 1) return 256;
	if(nivel == 2) return 64;
	if(nivel == 3) return 16;
	if(nivel == 4) return 4;
	if(nivel == 5) return 1;
}

int build(int node, int i, string s, char tree){
	if(tree == '1'){
		if(s[i] == 'p'){
			t1[node] = 'p';
			int j = i;
			//j: donde termino la rama
			j = build(node*4,j+1,s,'1');			
			j = build((node*4)+1,j+1,s,'1');
			j = build((node*4)+2,j+1,s,'1');
			j = build((node*4)+3,j+1,s,'1');
			return j;			
		}
		else{
			//if(s[i] == 'e' || s[i] == 'f')
			t1[node] = s[i];
			return i;
		}
	}
	else{
		//if(tree == 2)
		if(s[i] == 'p'){
			t2[node] = 'p';
			int j = i;
			//j: donde termino la rama
			j = build(node*4,j+1,s,'2');			
			j = build((node*4)+1,j+1,s,'2');
			j = build((node*4)+2,j+1,s,'2');
			j = build((node*4)+3,j+1,s,'2');
			return j;			
		}
		else{
			//if(s[i] == 'e' || s[i] == 'f')
			t2[node] = char(s[i]);
			return i;
		}
	}
}

int solve(int node){
	if((t1[node]=='f')||(t2[node]=='f')){
		return val_nodo_nivel(nivel(node));
	}
	if( ((t1[node]!='f') && (t2[node]!='f')) && ((t1[node]!='p') && (t2[node]!='p')) )
		return 0;
	
	int sum = 0, temp;
	sum += solve(node*4);
	sum += solve((node*4)+1);
	sum += solve((node*4)+2);
	sum += solve((node*4)+3);
	return sum;
}

int main()
{   ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	string s1,s2;
	cin>>n;
	while(n--){
		cin>>s1>>s2;
		build(1,0,s1,'1');
		build(1,0,s2,'2');
		cout<<"There are "<<solve(1)<<" black pixels.\n";
		t1.clear();
		t2.clear();
	}
	return 0;
}
