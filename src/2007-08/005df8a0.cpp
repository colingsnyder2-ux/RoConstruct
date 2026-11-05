// from server: 39% by colin
struct Node {
    Node* left;
    Node* parent;
    Node* right;
    char color;
    char pad[3];
    int key[3];
};

struct Tree {
    Node* head;
    int size;
};

struct Result {
    Node* first;
    Node* second;
    char inserted;
    char pad[3];
};

extern "C" void __stdcall sub_587c30(void*);
extern "C" char __stdcall sub_5de0d0(void*, void*);
extern "C" Result* __stdcall sub_5df0c0(Result*, Node*, int, int*);

struct S {
    char pad0[4];
    Tree* tree;
    Result* insert(int* key, Node* hint);
};

Result* S::insert(int* key, Node* hint)
{
    Node* head = tree->head;
    Node* cur = head->parent;
    char inserted = 1;
    Node* lower = head;
    Node* upper = 0;
    Result pos;

    if (cur->color == 0) {
        while (1) {
            int i = 0;
            int* k = key;
            int* nk = cur->key;
            while (i < 3) {
                if (*k < *nk) {
                    inserted = 1;
                    goto done_cmp;
                }
                if (*k > *nk) {
                    inserted = 0;
                    goto done_cmp;
                }
                i++;
                k++;
                nk++;
            }
            inserted = 0;
        done_cmp:
            if (inserted) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
            if (cur->color != 0) break;
        }
    }

    if (inserted) {
        if (lower == tree->head->left) {
            Result* r = sub_5df0c0(&pos, lower, 1, key);
            Result* out = (Result*)hint;
            out->first = r->first;
            out->second = r->second;
            out->inserted = 1;
            return out;
        }
        sub_587c30(&lower);
    }

    if (sub_5de0d0(lower->key, key)) {
        Result* r = sub_5df0c0(&pos, lower, 1, key);
        Result* out = (Result*)hint;
        out->first = r->first;
        out->second = r->second;
        out->inserted = 1;
        return out;
    }

    Result* out = (Result*)hint;
    out->first = lower;
    out->second = upper;
    out->inserted = 0;
    return out;
}
