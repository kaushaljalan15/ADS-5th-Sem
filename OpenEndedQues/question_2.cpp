#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void find_unique(int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        int num = i;
        bool visited[10] = {false};
        while (num)
        {
            if (visited[num % 10])
                break;
            visited[num % 10] = true;
            num = num / 10;
        }
        if (num == 0)
        {
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main()
{
    int l, r;
    cout << "Enter L and R: ";
    cin >> l >> r;
    find_unique(l, r);

    return 0;
}