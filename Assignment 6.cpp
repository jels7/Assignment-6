#include <iostream>


class BinarySearchTree; 
// Node class

struct Node {  // Node structure
    int value;  // Stores value of the node
    Node* left;  // Pointer to the left child
    Node* right;  // Pointer to the right child
};


class BinarySearchTree {  // Binary Search Tree class
private:
    Node* root; 

    Node* insertNode(Node* node, int value) {   // Inserting a node
        if (node == NULL) {  
            node = new Node();  // Creating a new node
            node->value = value;  // Assigning the value to the node
            node->left = node->right = NULL;
        } else if (value <= node->value) {   // If the value is less than or equal to the node value
            node->left = insertNode(node->left, value);
        } else {
            node->right = insertNode(node->right, value);  // If the value is greater than the node value
        }
        return node;
    }

    Node* minValueNode(Node* node) {  // Finding the minimum value node
        Node* current = node;
        while (current && current->left != NULL) {  
            current = current->left;  // Traversing to the leftmost node
        }
        return current;
    }

    Node* deleteNode(Node* node, int value) {  // Deleting a node
        if (node == NULL) return node;
        if (value < node->value) {
            node->left = deleteNode(node->left, value);  // If the value is less than the node value
        } else if (value > node->value) {
            node->right = deleteNode(node->right, value);  // If the value is greater than the node value
        } else {
            if (node->left == NULL) {
                Node* temp = node->right; 
                delete node;  // Deleting the node
                return temp;  
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right); // Finding the minimum value node in the right subtree
            node->value = temp->value;  // Assigning the value of the minimum value node to the current node
            node->right = deleteNode(node->right, temp->value);  // Deleting the minimum value node
        }
        return node;
    }

    void inorder(Node* node) {  // Inorder traversal
        if (node != NULL) { 
            inorder(node->left);  // Traversing to the leftmost node
            std::cout << node->value << " ";
            inorder(node->right);  // Traversing to the rightmost node
        }
    }

public:
    BinarySearchTree() : root(NULL) {}  // Constructor

    void insert(int value) {  // Inserting a value
        root = insertNode(root, value);
    }

    void remove(int value) {  // Removing a value
        root = deleteNode(root, value);
    }

    void printInorder() {  // Printing the inorder traversal
        inorder(root);
        std::cout << "\n";
    }
};

int main() {  // Main function
    BinarySearchTree bst; // Creating a binary search tree object
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    bst.printInorder();  // Printing the inorder traversal

    bst.remove(5);  // Removing a value
    bst.printInorder();

    return 0;
}
