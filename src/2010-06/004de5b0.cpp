// from server: 84% by atomic.potato
struct Node {
    char pad0[4];
    Node* left;
    Node* right;
    char pad10[0x151];
    unsigned char flag161;
};

struct Cmp {
    char compare(const void* other);
};

struct Container {
    char pad0[0x18];
    Node* header;
};

struct Result {
    void* p0;
    void* p4;
    void* p8;
    void* pC;
};

struct S {
    void find(Result* out, const void* key);
};

void S::find(Result* out, const void* key)
{
    Node* header = *(Node**)((char*)this + 0x18);
    Node* root = header->right;
    Node* lower = header;
    Node* upper = header;
    Node* cur = root;
    while (cur->flag161 == 0) {
        if (((Cmp*)((char*)cur + 0x10))->compare(key)) {
            cur = cur->right;
        } else {
            if (upper->flag161 != 0) {
                if (((Cmp*)key)->compare((char*)cur + 0x10)) {
                    upper = cur;
                }
            }
            lower = cur;
            cur = cur->left;
        }
    }
    Node* n;
    if (upper->flag161 != 0) {
        n = (*(Node**)((char*)this + 0x18))->right;
    } else {
        n = upper->left;
    }
    while (n->flag161 == 0) {
        if (((Cmp*)key)->compare((char*)n + 0x10)) {
            upper = n;
            n = n->left;
        } else {
            n = n->right;
        }
    }
    void* v = *(void**)this;
    out->p4 = lower;
    out->pC = upper;
    out->p0 = v;
    out->p8 = v;
}
