// from server: 70% by atomic.potato
extern "C" {
__declspec(dllimport) int __stdcall MSVCP90_string_less(const void*, const void*);
}

struct Node {
    char pad0[4];
    Node* left;
    Node* right;
    char pad8[0x55 - 12];
    char color;
    char pad56[3];
    char str[0x10];
};

struct Tree {
    char pad0[4];
    Node* head;
};

struct Result {
    Node* first;
    Node* second;
};

struct VScriptContext {
    char pad0[4];
    Tree* tree;
    Result find(const char* key);
};

Result VScriptContext::find(const char* key) {
    Result r;
    Node* head = tree->head;
    Node* x = head->left;
    Node* y = head;
    if (x->color == 0) {
        while (1) {
            if (MSVCP90_string_less(x->str, key)) {
                x = x->right;
            } else {
                if (y->color == 0) {
                    if (MSVCP90_string_less(x->str, key)) {
                        y = x;
                    }
                }
                r.first = x;
                x = x->left;
            }
            if (x->color != 0) break;
        }
    }
    if (y->color == 0) {
        x = tree->head->left;
    } else {
        x = y;
    }
    while (x->color == 0) {
        if (MSVCP90_string_less(x->str, key)) {
            y = x;
            x = x->right;
        } else {
            x = x->left;
        }
    }
    r.second = y;
    return r;
}
