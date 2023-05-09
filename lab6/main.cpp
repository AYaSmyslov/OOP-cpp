#include <iostream> 
 
using namespace std; 
 
struct Node { 
    int val; 
    int height; 
    Node* left; 
    Node* right; 
    Node(int x) : val(x), height(1), left(nullptr), right(nullptr) {} 
    //Node(int x) { 
    //    this->x = x; 
    //    left = NULL; 
    //    right = NULL; 
    //} 
}; 
 
int height(Node* node) { 
    return node ? node->height : 0; 
} 
 
int balanceFactor(Node* node) { 
    return node ? height(node->left) - height(node->right) : 0; 
} 
 
void fixHeight(Node* node) { 
    int leftHeight = height(node->left); 
    int rightHeight = height(node->right); 
    node->height = max(leftHeight, rightHeight) + 1; 
} 
 
Node* rotateRight(Node* node) { 
    Node* newRoot = node->left; 
    node->left = newRoot->right; 
    newRoot->right = node; 
    fixHeight(node); 
    fixHeight(newRoot); 
    return newRoot; 
} 
 
Node* rotateLeft(Node* node) { 
    Node* newRoot = node->right; 
    node->right = newRoot->left; 
    newRoot->left = node; 
    fixHeight(node); 
    fixHeight(newRoot); 
    return newRoot; 
} 
 
Node* balance(Node* node) { 
    fixHeight(node); 
    int bf = balanceFactor(node); 
    if (bf == 2) { 
        if (balanceFactor(node->left) < 0) { 
            node->left = rotateLeft(node->left); 
        } 
        return rotateRight(node); 
    } 
    else if (bf == -2) { 
        if (balanceFactor(node->right) > 0) { 
            node->right = rotateRight(node->right); 
        } 
        return rotateLeft(node); 
    } 
    return node; 
} 
 
Node* insert(Node* node, int val) { 
    if (!node) { 
        return new Node(val); 
    } 
    if (val < node->val) { 
        node->left = insert(node->left, val); 
    } 
    else { 
        node->right = insert(node->right, val); 
    } 
    return balance(node); 
} 
 
//void insert(Node* f, Node* n) { 
//    if (n->val > f->val) { 
//        if (f->right != NULL) insert(f->right, n); 
//        else f->right = n; 
//    } 
//    else { 
//        if (f->left != NULL) insert(f->left, n); 
//        else f->left = n; 
//    } 
//} 
 
void traverseInOrder(Node* node) { 
    if (!node) { 
        return; 
    } 
    traverseInOrder(node->left); 
    cout << node->val << " "; 
    traverseInOrder(node->right); 
} 
 
static int i = 0; 
 
void print(Node* f) { 
    if (f->left != NULL) print(f->left); 
    cout << f->val << '\t'; 
    if (f->right != NULL) print(f->right); 
} 
 
int menu() { 
    cout << "1. Append elem into tree" << endl; 
    cout << "2. Delete elem from tree" << endl; 
    /*cout << "1." << endl; 
    cout << "1." << endl; 
    cout << "1." << endl;*/ 
    int inp = 0; 
    cout << "select: "; 
    cin >> inp; 
    return inp; 
} 
 
Node* deleteNode(Node* root, int key) { 
    if (root == nullptr) { 
        return root; 
    } 
    if (key < root->val) { 
        root->left = deleteNode(root->left, key); 
    } 
    else if (key > root->val) { 
        root->right = deleteNode(root->right, key); 
    } 
    else { 
        if (root->left == nullptr) { 
            Node* temp = root->right; 
            delete root; 
            return temp; 
        } 
        else if (root->right == nullptr) { 
            Node* temp = root->left; 
            delete root; 
            return temp; 
        } 
        Node* temp = root->right; 
        while (temp->left != nullptr) { 
            temp = temp->left; 
        } 
        root->val = temp->val; 
        root->right = deleteNode(root->right, temp->val); 
    } 
    return root; 
} 
 
int main() { 
    Node* root = nullptr; 
    int val; 
    /*root = insert(root, 10); 
    root = insert(root, 5); 
    root = insert(root, 15); 
    root = insert(root, 1); 
    root = insert(root, 7); 
    root = insert(root, 12); 
    root = insert(root, 18);*/ 
 
    root = insert(root, 3); 
    root = insert(root, 18); 
    root = insert(root, 8); 
    root = insert(root, 15); 
    root = insert(root, 1); 
    root = insert(root, 2); 
    root = insert(root, 6); 
    root = insert(root, 7); 
    root = insert(root, 12); 
    root = insert(root, 16); 
    root = insert(root, 5); 
    root = insert(root, 17); 
    root = insert(root, 4); 
 
    /*print(root); 
    cout << endl; 
    traverseInOrder(root); 
    cout << endl;*/ 
    do { 
        if (root != nullptr) { 
            print(root); 
            cout << endl; 
        } 
        else cout << "Tree is null" << endl; 
        switch (menu()) 
        { 
        case 1: 
            cout << "Input num: "; 
            cin >> val; 
            if (root == nullptr) root = new Node(val); 
            else 
                root = insert(root, val); 
                root = balance(root); 
            break; 
        case 2: 
            cout << "Input num: "; 
            cin >> val; 
            if (root == nullptr) root = new Node(val); 
            else 
                root = deleteNode(root, val); 
            break; 
        default:
            break; 
        } 
    } while (true); 
    return 0; 
}