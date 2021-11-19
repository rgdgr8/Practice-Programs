#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int n,m;
        cin>>n>>m;
        double vitamins[n];
        double prices[n];
        for(int i=0;i<n;i++){cin>>vitamins[i]>>prices[i];}

        double optVitamins[n+1][m+1];
        for(int i=0;i<n+1;i++){optVitamins[i][0] = 0;}
        for(int i=0;i<m+1;i++){optVitamins[0][i] = 0;}

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                optVitamins[i][j] = optVitamins[i-1][j];
                if(prices[i-1]<=j){
                    double withI = (optVitamins[i-1][(int)(j-prices[i-1])] + vitamins[i-1]);
                    double withoutI = optVitamins[i-1][j];

                    if(withI>withoutI){
                        optVitamins[i][j] = withI;
                    }
                }
            }
        }

	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++)
			cout<<optVitamins[i][j]<<" ";
		cout<<endl;
	}
}
