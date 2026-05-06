#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.length();

    string doubled = s + s;

    vector<int> freq(26, 0);

    int left = 0;
    int currentSum = 0;
    int maxSum = 0;

    for (int right = 0; right < 2 * n; right++)
    {

        int idx = doubled[right] - 'a';

        currentSum += (idx + 1);
        freq[idx]++;

        while (freq[idx] > 1 || (right - left + 1) > n)
        {

            int leftIdx = doubled[left] - 'a';

            currentSum -= (leftIdx + 1);
            freq[leftIdx]--;

            left++;
        }

        maxSum = max(maxSum, currentSum);
    }

    cout << maxSum << endl;

    return 0;
}