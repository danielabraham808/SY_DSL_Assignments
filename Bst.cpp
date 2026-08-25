#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

// Create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Inorder: Left -> Root -> Right
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " -> ";
        inorder(root->right);
    }
}

// Preorder: Root -> Left -> Right
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " -> ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder: Left -> Right -> Root
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " -> ";
    }
}

// Insert a node
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Find the smallest node
Node* findMin(Node* root) {
    Node* temp = root;

    while (temp != NULL && temp->left != NULL) {
        temp = temp->left;
    }

    return temp;
}

// Delete a node
Node* deleteNode(Node* root, int value) {

    if (root == NULL) {
        return root;
    }

    // Search for the node
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {

        // Node has no left child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Node has no right child
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node has two children
        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main() {

    Node* root = NULL;
    int choice, value;

    do {
        cout << "\n===== Binary Search Tree Menu =====";
        cout << "\n1. Insert Node";
        cout << "\n2. Delete Node";
        cout << "\n3. Inorder Traversal";
        cout << "\n4. Preorder Traversal";
        cout << "\n5. Postorder Traversal";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;

                root = insert(root, value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;

                root = deleteNode(root, value);
                break;

            case 3:
                cout << "Inorder traversal: ";
                inorder(root);
                break;

            case 4:
                cout << "Preorder traversal: ";
                preorder(root);
                break;

            case 5:
                cout << "Postorder traversal: ";
                postorder(root);
                break;

            case 6:
                cout << "Program Exited.";
                break;

            default:
                cout << "Invalid Choice!";
        }

    } while (choice != 6);

    return 0;
}