// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Root { char pad[0x54]; int id; };
struct Owner { Root* root; };
struct Node {
    Owner* owner;
    int pad[2];
    int state;
    int pad2;
    char pad3;
    unsigned char kind;
};
int sameRoot(const Node* a, const Node* b)
{
    return a->kind == b->kind
        && a->state == 1 && b->state == 1
        && a->owner->root->id == b->owner->root->id;
}
