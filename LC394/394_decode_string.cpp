#include <iostream>
#include <stack> 
#include <unordered_map>
#include <vector>

std::string decodeString(std::string s) {
    std::stack<char> stack;
    for (int i=0; i<s.size(); i++) {
        if (s[i] != ']') {
            stack.push(s[i]); 
        }
        else {
            std::string str = "";
            while (!stack.empty() && stack.top() != '[') {
                str = stack.top() + str;
                stack.pop();
            }
            stack.pop(); // remove '['
            std::string k = "";
            while (!stack.empty() && (stack.top() >= '0' && stack.top() <= '9')) {
                k = stack.top()+k;
                stack.pop(); 
            }
            for (int j=0; j<std::stoi(k); j++) {
                for (int l=0; l<str.size(); l++) {
                    stack.push(str[l]);
                }
            }
        }
    }
    std::string res = "";
    while (!stack.empty()) {
        res = stack.top() + res;
        stack.pop(); 
    }
    return res; 
}
int main () {
    std::unordered_map<std::string, std::string> testcases = { 
        {"2[abc]3[cd]ef", "abcabccdcdcdef"},
        {"3[a]2[bc]", "aaabcbc"},
        {"3[a2[c]]", "accaccacc"},
        {"abc3[cd]xyz", "abccdcdcdxyz"}
    };
    for (auto& i: testcases) {
        std::cout << "Input: " << i.first << std::endl;
        std::string res = decodeString(i.first);
        std::cout << "Result: " << res << std::endl;
        bool correct = res == i.second ? true : false; 
        std::cout << "Correct: " << correct << std::endl << std::endl;
    }
    return 0; 
}