/*
input:
3
1 2 3
2 1 3
1 2 3

2 1 3
1 2 3
1 2 3
output:
1-1
2-2
3-3

*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MaxM = 20;

int * GS(int male[][MaxM], int female[][MaxM], int M){
	int * match = new int[M];
	bool isMatch[MaxM];
	int w;
	int cnt = 0;
	match[0] = 0;
	for(int i = 1; i<=M; i++){
		isMatch[i] = false;
		match[i] = 0;
	}
	while(cnt!=M){
		for(int m = 1; m <= M; m++){
			for(int f = 1; f <= M; f++){
				if(isMatch[m]==true){
					break;
				}
				w = male[m][f];
				if(match[w]==0){
					match[w] = m;
					isMatch[m] = true;
					cnt++;
				}
				else{
					int i = 1;
					for(i = 1; i<= M; i++){
						if(female[w][i]==m || female[w][i] == match[w]){
							//cout<<match[w]<<endl;
							break;
						}
					}
					if(female[w][i]==m){
						isMatch[match[w]]= false;
						match[w] = m;
						isMatch[m] = true;
					}
				}
			}
		}
			
	}
	return match;
}
int main() {
	// your code goes here
	int M;
	cin>>M;
	// input preference
	int male[MaxM][MaxM];
	int female[MaxM][MaxM];
	for(int m = 1; m <= M; m++)
	{
		for(int f = 1; f <= M; f++)
		{
			cin>>male[m][f];
		}
	}
	
	for(int m = 1; m <= M; m++)
	{
		for(int f = 1; f <= M; f++)
		{
			cin>>female[m][f];
		}
	}
	int *match =GS(male,female,M);
	//cout<<*match<<endl;
	for(int i = 1; i<=M; i++)
	{
		cout<<i<<"-"<<match[i]<<endl;
	}
	return 0;
}
