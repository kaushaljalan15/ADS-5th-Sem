#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void remove_two_greatest(vector<int> arr)
{
    vector<int> ans;
    priority_queue<int, vector<int>, less<int>> heap;
    for (int i = 0; i < (int)arr.size(); ++i)
    {
        heap.push(arr[i]);
    }
    if (heap.size() <= 2)
        cout << "Size too small \n";
    else
    {
        heap.pop();
        heap.pop();
        while (!heap.empty())
        {
            ans.push_back(heap.top());
            heap.pop();
        }
        sort(ans.begin(), ans.end());
        cout << "Ans:";
        for (int i = 0; i < (int)ans.size(); ++i)
            cout << ans[i] << " ";
        cout << "\n";
    }
}

int main()
{

    int n;
    cout << "Number of test cases: ";
    cin >> n;
    while (n--)
    {
        int k;
        cout << "\nNumber of digits: ";
        cin >> k;
        vector<int> arr;
        cout << "Enter digits: ";
        for (int i = 0; i < k; ++i)
        {
            int ele;
            cin >> ele;
            arr.push_back(ele);
        }
        remove_two_greatest(arr);
    }
    return 0;
}