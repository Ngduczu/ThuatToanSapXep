#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr) {
    int maxVal = 1000000;
    int minVal = 1;
    int range = maxVal - minVal + 1;
    vector<int> count(range, 0);
    
    for (int num : arr) {
        count[num - minVal]++;
    }
    
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + minVal;
            count[i]--;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    countingSort(arr);
    for (int num : arr) {
        cout << num <<" ";
    }
    return 0;
}
