// from server: 37% by atomic.potato
struct Node {
    Node* left;
    Node* parent;
    Node* right;
    char pad[0x19 - 0xc];
    unsigned char flag;
};

struct Tree {
    Node* head;
};

struct Result {
    Node* node;
    unsigned char flag;
    char pad[3];
};

struct V {
    char pad0[4];
    Tree* tree;
    Result insert_result(Node* hint, int a, Node* n, void* out);
};

extern "C" int cmp_72b3e0(void* self, void* key);
extern "C" void fn_82fc10(void* self);
extern "C" void* fn_574d80(V* self, void* out, int a, Node* n, void* key);

Result V::insert_result(Node* hint, int a, Node* n, void* out) {
    Node* head = tree->head;
    Node* cur = head->parent;
    unsigned char ok = 1;
    while (cur->flag == 0) {
        if (cmp_72b3e0(n, (char*)cur + 0xc)) {
            ok = 1;
            cur = cur->left;
        } else {
            ok = 0;
            cur = cur->right;
        }
    }
    Node* pos = hint;
    if (ok) {
        if (hint == tree->head) {
            void* r = fn_574d80(this, out, 1, hint, n);
            Result res;
            res.node = *(Node**)r;
            res.flag = 1;
            return res;
        }
        fn_82fc10(&pos);
        pos = hint;
    }
    if (cmp_72b3e0((char*)pos + 0xc, n)) {
        void* r = fn_574d80(this, out, ok, hint, n);
        Result res;
        res.node = *(Node**)r;
        res.flag = 1;
        return res;
    }
    Result res;
    res.node = pos;
    res.flag = 0;
    return res;
}
