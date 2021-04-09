#include <stack>
using namespace std; 
class Node {
    public:
        int val; 
        Node* prev;
        Node* next; 
        Node* child;
        Node(int val) {
            this->val = val;
        }
};

Node* flatten(Node* head) {
    if (head == nullptr) return nullptr;

    Node* prev = nullptr; 
    stack<Node*> stack; 
    stack.push(head); 

    while (!stack.empty()) {
        Node* curr = stack.top();
        stack.pop(); 

        if (curr->next != nullptr) stack.push(curr->next);
        if (curr->child != nullptr) stack.push(curr->child);

        if (prev != nullptr) {
            prev->next = curr; 
            curr->prev = prev; 
            prev->child = nullptr; 
        }
        prev = curr; 
    }
    
    return head; 
}

int main() {
    return 0;
}