// from server: 100% by king_originala
struct Node {
    Node* left;
    Node* parent;
    Node* right;
    unsigned char key[41];
    unsigned char nil;
};

extern "C" bool __cdecl compare(const void*, const void*);

struct S {
    unsigned char padding[24];
    Node* head;

    Node* find(const void* key);
};

Node* S::find(const void* key)
{
    Node* current = head->parent;
    Node* result = head;

    if (!current->nil) {
        do {
            if (compare(current->key, key)) {
                current = current->right;
            } else {
                result = current;
                current = current->left;
            }
        } while (!current->nil);
    }

    return result;
}
