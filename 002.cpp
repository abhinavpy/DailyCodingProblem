/*
Problem #2 [Hard]
June 14th, 2019

Good morning! Here's your coding interview problem for today.

This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?

*/

#include<bits/stdc++.h>
using namespace std;

void printProductArray(vector<int> &arr)
{
	int n = arr.size();
	vector <int> prod(n);
	vector <int> left(n);
	vector <int> right(n);
	left[0] = 1;
	right[n - 1] = 1;
	for(int i = 1, j = n - 2; i < n && j >= 0; ++i, --j)
	{
		left[i] = arr[i - 1] * left[i - 1];
		right[j] = arr[j + 1] * right[j + 1];
	}
	for(int i = 0; i < n; ++i)
	{
		prod[i] = left[i] * right[i];
		cout << prod[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n;
	cout << "Enter the number of elements" << endl;
	cin >> n;
	vector<int> arr(n);
	cout << "Enter elements into the array: " << endl;
	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	printProductArray(arr);
	return 0;
}