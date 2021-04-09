#include <vector>
#include <iostream>
using namespace std;
int reverse(int);
int main() {
    cout << reverse(1534236469) << endl;
    return 0;
}
int reverse(int x) {
    // single digit edge case
    if (x < 10 && x > -10) return x; 

    vector<int> nums; 
    // extract integers
    while (x != 0) {
        int n = x%10;
        nums.push_back(n);
        x -= n; 
        x /= 10; 
    }
    int start = 0;
    // edgcase, leading zero 
    while(nums[start] == 0) start++; 
    
    int res = nums[start++]; // help determine sign
    bool neg = res < 0 ? true : false; 
    for (int i=start; i<nums.size(); ++i) {
        if (!neg && res > INT_MAX/10) return 0;
        if (neg && res < INT_MIN/10) return 0;
        res = res*10 + nums[i];
    }
    return res; 
}