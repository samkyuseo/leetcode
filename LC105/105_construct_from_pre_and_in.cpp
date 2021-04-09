#include <vector>
#include <unordered_map>

using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left; 
    TreeNode* right; 
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {};
};

class Solution {
public:
    int preorderIndex = 0; 
    unordered_map<int,int> map; 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0; i<inorder.size(); i++) {
            map[inorder[i]] = i; 
        }
        return helper(preorder, 0, inorder.size()-1);
    }
    //  preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    TreeNode* helper(vector<int>& preorder, int start, int end) {
        if (end - start < 0) return nullptr;

        TreeNode* root = new TreeNode(preorder[preorderIndex++]);

        root->left = helper(preorder, start, map[root->val]-1);
        root->right = helper(preorder, map[root->val]+1, end);

        return root; 
    }
};

int main() {
    return 0;
}

