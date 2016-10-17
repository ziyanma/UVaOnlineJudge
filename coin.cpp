#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int k;
	cin>>k;
	for (int i =0; i<k; i++){
		int m;
		cin>>m;
		if (m == 0){
			cout<<"0"<<endl;

		} else if (m==1){
			int temp;
			cin>>temp;
			cout<<temp<<endl;
		} else if (m==2){
			int a,b;
			cin>>a>>b;
			cout<<abs(a-b)<<endl;
		}
		else{
		int array[100];
		long sum = 0; 
		for (int j = 0; j< m ; j++){
			cin>>array[j];
			sum+=array[j];
		}
		bool** da;
		da = new bool*[m];
		da[0] = new bool[sum/2+1];
		da[0][0] =1;
		
		for (int j = 1; j<sum/2+1; j++){
			da[0][j] = 0;
		}
		da[0][array[0]] = 1;
		for (int j = 1; j < m; j++){
			da[j] = new bool[sum/2+1];
			da[j][0] = 1; 
			for (int l = 0; l<sum/2 + 1; l++){
				int temp = array[j];
				if (l >= temp){
					da[j][l] = da[j-1][l-temp] || da[j-1][l];
				} else {
					da[j][l] = da[j-1][l];
				}
				//cout<<da[j][l]<<" ";
			}
			//cout<<endl;
			delete [] da[j-1];
		}
		int t = sum/2;

		while (t!=0){
			if (da[m-1][t]){
				cout<< (sum- t*2)<<endl;
				break;
			}
			t--;
		}
		delete [] da[m-1];
		delete [] da;
		}
	}
}