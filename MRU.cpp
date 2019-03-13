#include<bits/stdc++.h>
using namespace std;


int main(){

	int n;
	cout<<"Enter number of pages\n";
	cin>>n;
	cout<<"Enter the number of frame \n";
	int frame;
	cin>>frame;
	int a[n];
	cout<<"Enter the references to the pages \n";
	int i=0;
	for(i=0;i<n;i++){
		cin>>a[i];
	}

	map<int,int> m;
	int page_fault=0,page_heat=0;

	for(i=0;i<n;i++){
		if(i<frame){
			page_fault++;
			m[a[i]]=i+1;
		}
		else{
			if(m.count(a[i])){
				page_heat++;
                m[a[i]]=i+1;
			}
			else{
				int m1=0,ind=-1;
				for(auto j:m){
					if(j.second>m1){
						m1=j.second;
						ind=j.first;
					}
				}
				m.erase(ind);
				m[a[i]]=i+1;
				page_fault++;
			}
		}
	}

	cout<<"Page Fault :: "<<page_fault<<endl;
	cout<<"Page Heat :: "<<page_heat<<endl;

}
