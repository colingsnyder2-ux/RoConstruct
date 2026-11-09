// from server: 25% by Intel
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int key;
    char is_nil;
};

struct TreeRoot {
    Node* header;
    Node* nil;
};

struct Container {
    char pad[4];
    TreeRoot* tree;
};

extern "C" void __stdcall func_0069aec0(Container* thisptr, int key, Node** result_pair) {
    Node* root = thisptr->tree->header->parent;
    Node* nil = thisptr->tree->nil;
    Node* y = nil;
    Node* x = root;

    if (!x->is_nil) {
        while (true) {
            if (x->key < key) {
                if (x->right->is_nil) break;
                x = x->right;
            } else {
                if (x->is_nil) break;
                if (key < x->key) {
                    y = x;
                    x = x->left;
                } else {
                    y = x;
                    x = x->right;
                }
            }
        }
    }

    if (!y->is_nil) {
        x = thisptr->tree->header->parent;
        while (!x->is_nil) {
            if (key < x->key) {
                y = x;
                x = x->left;
            } else {
                x = x->right;
            }
        }
    } else {
        x = root;
        while (!x->is_nil) {
            if (key < x->key) {
                x = x->left;
            } else {
                y = x;
                x = x->right;
            }
        }
    }

    Node* lower = x;
    while (!lower->is_nil) {
        if (key < lower->key) {
            y = lower;
            lower = lower->left;
        } else {
            lower = lower->right;
        }
    }

    result_pair[0] = y;
    result_pair[1] = x;
}
