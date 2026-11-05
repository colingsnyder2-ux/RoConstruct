// from server: 64% by Intel





struct Node {
    Node* left;
    Node* right;
    Node* parent;
    char is_nil;
    char key[12];
};

extern "C" int __stdcall StringCompare(const char* a, const char* b);

struct SharedPtr {
    Node* get_lower_bound(const char* key);
};

Node* SharedPtr::get_lower_bound(const char* key) {
    Node* root = *(Node**)(this + 0x10);
    Node* current = root->left;
    Node* result = root;

    while (!current->is_nil) {
        if (StringCompare(current->key, key) >= 0) {
            result = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return result;
}
