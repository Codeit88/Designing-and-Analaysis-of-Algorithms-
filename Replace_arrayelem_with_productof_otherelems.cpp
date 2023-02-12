#include<iostream>
using namespace std;
void print(int*arr,int size){
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void replaced_array(int*arr,int size){
	int i = 0;
	while (i < size) {
		int product=1;  //for each replacement product starts with 1
		for (int j = 0; j < size; j++)
		{
			if (j != i)     //except for the current elem
				product *= arr[j];
		}
		arr[i] = product;    //storing/replacing array elem with product
		print(arr, 4);   //prinitng the array after each iteration
		i++;
	}
}
int main() {
	int* arr{ new int[4] {2,1,3,2} };
	//to print the initial array
	print(arr,4);
	//this will replace array elems with product of every other array elem
	replaced_array(arr, 4);
	return 0;
}
