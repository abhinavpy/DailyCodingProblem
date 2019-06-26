/*
Problem #1 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?*/

#include<bits/stdc++.h>
using namespace std;

bool findSum(vector <int> &arr, int k)
{
	int n = arr.size();
	sort(arr.begin(), arr.end());
	int head = 0, tail = n-1;
	int temp = head + tail;
	bool ans = false;
	while(head < tail)
	{
		temp = arr[head] + arr[tail];
		if(temp > k) {
			--tail;
		}
		else if(temp < k) {
			++head;
		}
		else {
			ans = true;
			break;
		}
	}

	return ans;
}

int main()
{
	int n;
	cout << "Enter the number of elements in the array: ";
	cin >> n;
	vector<int> arr(n);
	cout << "Enter " << n << "elements into the array: " << endl;
	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int k;
	cout << "Enter k: ";
	cin >> k;
	bool ans = findSum(arr, k);
	if(ans) cout << "Yes, sum found" << endl;
	else cout << "No, sum not found" << endl;
	return 0;
}