#include<vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
int main() {
    return 0; 
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    m--;
    n--;
    for (int i=nums1.size()-1; i >=0; i--) {
        if ((m >=0 && n < 0) || nums1[m] > nums2[n]) {
            nums1[i] = nums1[m];
            m--; 
        }
        else if ((n >=0 && m < 0) || nums1[m] <= nums2[n]){
            nums1[i] = nums1[n];
            n--; 
        }
    }
}