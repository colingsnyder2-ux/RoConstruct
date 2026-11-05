// from server: 29% by Intel
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    char color;
    int key;
};

struct Tree {
    Node* header;
    Node* root() const { return header->parent; }
};

struct Pair {
    Node* first;
    Node* second;
};

struct RBX_VButton_FactoryProduct {
    Tree tree;
    void find_lower_bound(int key, Pair* out) const;
};

void RBX_VButton_FactoryProduct::find_lower_bound(int key, Pair* out) const {
    Node* header = tree.header;
    Node* root = header->parent;
    Node* current = root;
    Node* candidate = header;

    if (header->color == 0) {
        Node* y = out->first;
        while (current->color != 0) {
            if (current->key < y->key) {
                current = current->right;
            } else {
                if (header->color == 0) {
                    if (y->key < current->key) {
                        candidate = current;
                        current = current->left;
                    } else {
                        candidate = current;
                        current = current->right;
                    }
                } else {
                    candidate = current;
                    current = current->left;
                }
            }
        }
    }

    if (candidate->color == 0) {
        current = root;
        candidate = header;
    }

    while (current->color != 0) {
        if (key < current->key) {
            candidate = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }

    out->first = candidate;
    out->second = current;
}
