// from server: 100% by Yeetserama
// from server: 100% by colin
// from server: 96% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Node {
    unsigned char padding0[4];
    char* data;
    unsigned char padding1[124];
    Node* parent;
};

struct S {
    void* find(const char*);
    void* search(Node*, bool);
};

void* S::search(Node* node, bool recursive)
{
    const char* key = node->data + 4;
    void* result = find(key);
    if (result)
        return result;

    if (recursive && node->parent)
        return search(node->parent, true);

    return 0;
}
