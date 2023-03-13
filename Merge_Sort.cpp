#include<iostream>
using namespace std;
//conquer and merging stage
void Merge(int*arr,int p,int q,int r){
	int size1 = q - p + 1;
	int size2 = r - q;
	int* temp1 = new int[size1], * temp2 = new int[size2];
	//temp1 is for left subarray
	//temp2 is for right subarray
	for (int i = 0; i < size1; i++){
		temp1[i] = arr[p + i];
	}
	for (int i = 0; i < size2; i++) {
		temp2[i] = arr[q + i];
	}
	int j = 0, k = 0;
	//for iteration in sub arrays
	for (int i = p; i < r; i++)
	{
		if (temp1[k] > temp2[j]) {
			arr[i] = temp1[k];
			k++;
		}
		else if(temp1[k]<temp2[j]){
			arr[i] = temp2[j];
			j++;
		}
		else{
			arr[k]=temp1[k];
			k++;
			j++;
		}
	}
}
//divide the two arrays
void Merge_sort(int*arr,int p,int r){
    //p is start and r is the end
	if(p < r) {
		//q is the mid
		int q = (p + r) / 2;
		Merge_sort(arr,p,q);
		Merge_sort(arr,q+1,r);
		Merge(arr,p,q,r);
  }
}
//display an array
void disp(int* arr, int size) {
	int i = 0;
	while (i < size) {
		cout << arr[i] << " ";
		i++;
	}
	cout << endl;
}
int main() {
	int* arr{ new int[15] {52,56,44,34,62,68,58,57,47,31,66,48,36,27,37} };
	//starting from 1st value towards end of the array
	disp(arr, 15);
	Merge_sort(arr,0,15);
	disp(arr, 15);
	return 0;
}
