// from server: 23% by atomic.potato
struct Node {
    Node* left;
    Node* right;
    int key;
    int value;
    char color;
};

struct S {
    Node* root;
    int find(int* arg);
};

int S::find(int* arg) {
    Node* n = root->right;
    if (n->color != 0) {
        return 0;
    }
    int a = arg[0];
    int b = arg[1];
    while (n->color == 0) {
        if (a > n->key || (a == n->key && b >= n->value)) {
            n = n->right;
        } else {
            n = n->left;
        }
    }
    return 0;
}
