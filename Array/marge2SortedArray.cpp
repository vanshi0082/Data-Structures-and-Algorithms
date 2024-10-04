#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, const vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();

    // Resize nums1 to hold elements of nums2
    nums1.resize(m + n);

    // Copy elements from nums2 to nums1
    for (int j = 0, i = m; j < n; j++) {
        nums1[i] = nums2[j];
        i++;
    }

    // Sort the merged array
    sort(nums1.begin(), nums1.end());
}

int main() {
    vector<int> nums1 = {2, 3, 4, 5}; // Assuming nums1 should be resized to accommodate nums2
    vector<int> nums2 = {32, 12, 45, 7};

    merge(nums1, nums2);

    cout << "The Merged Array is: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
