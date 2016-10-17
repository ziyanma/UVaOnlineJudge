#include <iostream>
using namespace std;

int main(){
	int k,m,n;
	cin>>k;
	for (int z = 0; z<k; z++){
		cin>>n>>m;
		int** da = new int*[n+1];
		int* arr = new int[n+1];
		for (int i=1; i<=n; i++){
			cin>>arr[i];
		}
		for (int i =0; i<=n; i++){
			da[i] = new int[m];
			for (int j = 0; j<m; j++){
				da[i][j] = 0;
			}
		}
		da[0][0] = 1;
		for (int i = 1; i<=n; i++){
			for (int j =0; j<m; j++){
			//	cout<< (j-arr[i])%m <<" "<<(j+arr[i])<<endl;
				da[i][j] = (da[i-1][ ((j-arr[i]) % m + m )%m] 
							|| da[i-1][ ((j+arr[i]) % m+ m )%m]);
			}
		}
		if (da[n][0]){
			cout<<"Divisible"<<endl;
		}else{
			cout<<"Not divisible"<<endl;
		}
		delete [] arr;
		for (int i=0; i<=n; i++){
			for (int j = 0; j< m ;j++){
			//	cout<<da[i][j]<<" ";
			}
			//   cout<<endl;
			delete[] da[i];
		}
		delete [] da;

	}
}
