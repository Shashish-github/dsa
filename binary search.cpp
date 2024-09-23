#include<iostream>
using namespace std;
int binarysearch(int arr[],int size,int key ){
	int start=0;
	int end=size-1;
	int mid= start+(end-start)/2;
	while(start<=end){
		if(key==arr[mid])
		return mid;
		else if (key>=mid){
			start=mid+1;
		}
		else
		end=mid-1;
		mid= start+(end-start)/2;
	}
	return -1;
}
int main(){
	int even[6]={1,2,3,4,5,6};
	int index=binarysearch(even,6,3);
	cout<<"index of 4 is "<<index<<endl;
	return 0;
}

