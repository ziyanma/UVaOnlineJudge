#include <iostream>
#include <vector>

using namespace std;

int da[51][51];


int recursive(int min, int max, vector<int>& v){
	if (da[min][max]!=0) return da[min][max];
	if (max==min) return 0;
	else if(max == min+1) {
		da[min][max] = v[max]-v[min];
		return da[min][max];
	}
	else {
		int mincut = -1;
		for (int i =min+1; i<max; i++){
			int temp = recursive(min,i,v) + recursive(i,max,v) ;
			if (i>min+1){
				temp+=v[i]-v[min];
			}
			if (i+1<max){
				temp+=v[max]-v[i];
			}
			if (mincut==-1){
				mincut = temp;
			} 
			else {
				if (temp<mincut){
					mincut = temp;
				}
			}

		}
		da[min][max]=mincut;
		return mincut;
	}
}

int main(){
	int k,n;
	vector<vector<int> > v;
	int index = 0;
	while (true){
		cin>>k;
		if (k==0) break;
		cin>>n;
		vector<int> tempp;
		v.push_back(tempp);
		v[index].push_back(0);
		for (int i =1; i <= n; i++){
			int temp;
			cin>>temp;
			v[index].push_back(temp);
		}
		v[index].push_back(k);
		index++;
	}
	for (int m = 0; m<index; m++){
		for (int i = 0; i<v[m].size(); i++){
			for (int j = 0; j<v[m].size(); j++){
				da[i][j]=0;
			}
		}
		if (v[m].size() == 2){
			cout<<"The minimum cutting is 0."<<endl;
		}
		else
		{cout<<"The minimum cutting is "<<recursive(0,v[m].size()-1,v[m])<<"."<<endl;}
		// for (int i = 0; i<v[m].size(); i++){
		// 	for (int j = 0; j<v[m].size(); j++){
		// 		cout<<da[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		
	}
}