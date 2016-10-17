#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

int maxi(int a, int b){
	if (a<b) return b;
	else 
		return a;
}
int main(){
	int k,m,n; 
	cin>>k;
	//ofstream output("b.txt");
	for (int z = 0 ; z<k; z++){
		cin>>m>>n;
		long** da;
		long* sum = new long[m];
		long* arr = new long[m];
		long** rec = new long*[n];
		da = new long*[n];
		for (int i =0; i<n;i++){
			da[i] = new long[m];
			rec[i] = new long[m];
			for (int j = 0; j<m; j++){
				da[i][j]=0;
			}
		}
		cin>>arr[0];
		sum[0] = arr[0];
		for (int i =1; i<m; i++){
			cin>>arr[i];
			sum[i] = sum[i-1]+arr[i];
			//cout<<sum[i]<<" ";
		}
		//cout<<endl;

		for (int i =0; i<m; i++){
			da[0][i] = sum[i];
		}
		for (int i = 1; i<n; i++){
			for (int j = 0; j<m; j++){
				int min = sum[j];
				int pos = j;
				for (int l = 0; l<j; l++){
					int temp = maxi(da[i-1][l],(sum[j]-sum[l]));
					if (temp<min) {
						min = temp;
						pos = l;
					}
				}
				da[i][j] = min;
				rec[i][j] = pos;
			}
		}

		long maxd = da[n-1][m-1];
		vector< vector <int> > vec;
		long summ = 0;
		int index = 0;
		vector<int> temp;
		vec.push_back(temp);
		for (int i = m-1; i>= 0; i--){
			
			//cout<<summ<<" "<<maxd<<"  ";
			if ((n-vec.size())>=i+1){
				//cout<<i;
				vector<int> tent;
				tent.push_back(arr[i]);
				vec.push_back(tent);
				index++;
			}else{
				summ+=arr[i];
				if (summ<=maxd){
					vec[index].push_back(arr[i]);
				} else{
					summ = arr[i];
					vector<int> tent;
					vec.push_back(tent);
					index++;
					vec[index].push_back(arr[i]);
				}
			}
		}

		// int count = vec.size();
		// cout<<count<<endl;
		// cout<<n<<endl;
		// if (count<n){
		// 	cout<<" ";
		// 	for (int i = 0; i<n-count; i++){
		// 		cout<<"/ ";
		// 	}
		// }
		for (int i = vec.size()-1; i>=0; i--){
			for (int j = vec[i].size()-1; j>=0; j--){
				cout<<vec[i][j];
				if ((i!=0)||(j!=0)){
					cout<<" ";
				}
			}
			if (i!=0) {cout<<"/ ";}

		}
		cout<<endl;
		for (int i =0; i<n;i++){
			delete [] da[i];
			delete [] rec[i];
		}
		delete [] da;
		delete [] rec;
	}
	//output.close();
}
