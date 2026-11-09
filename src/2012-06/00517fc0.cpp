// from server: 52% by Intel
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    char field_5d;
};

struct Iterator {
    Node* current;
    Node* getNext();
};

Node* Iterator::getNext() {
    Node* node = current;
    if (node->field_5d)
        return current;

    Node* right = node->right;
    if (!right->field_5d) {
        Node* leftmost = right;
        while (!leftmost->left->field_5d)
            leftmost = leftmost->left;
        current = leftmost;
        return current;
    }

    Node* parent = node->parent;
    while (!parent->field_5d && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }
    current = parent;
    return current;
}
