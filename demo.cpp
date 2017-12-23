#include <bits/stdc++.h>
using namespace std;

#define TAG1 20
#define TAG2 20

bool tag[TAG1][TAG2];
long long mem[TAG1][TAG2];

long long sub(long long n,long long d){
  if(n==0)
    return 1;
  long long ret=0;
  for(int dim=1;dim<d+1;dim++){
    if(dim==1)
      ret+=1;
    else if(dim*dim<=n){
      if((n-dim*dim<TAG1) && dim<TAG2){
	if(tag[n-dim*dim][dim])
	  ret+=mem[n-dim*dim][dim];
	else{
	  long long tmp = sub(n-dim*dim,dim);
	  tag[n-dim*dim][dim]=true;
	  mem[n-dim*dim][dim]=tmp;
	  ret+=tmp;
	}
      }else
	ret+=sub(n-dim*dim,dim);
    }
  }
  return ret;
}

int main(){
  long long n;
  cin >> n;
  for(int i=0;i<TAG1;i++){
    for(int j=0;j<TAG2;j++)
      tag[i][j]=false;
  }
  long long ret=0,dim=1;
  while(dim*dim<=n){
    ret+=sub(n-dim*dim,dim);
    dim+=1;
  }
  cout<<"number of c*-alg with dim="<<n<< " :" << ret<<endl;
  return 0;
}
