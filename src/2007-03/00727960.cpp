// from server: 100% by tester
struct Node {
    Node* next;
    Node* prev;
    Node* parent;
    char pad[0x25 - 0x0C];
    char color;
};

struct S {
    void insert(Node*);
};

void S::insert(Node* val)
{
    Node* pos = *(Node**)((char*)val + 8);
    Node* next = pos->next;
    *(Node**)((char*)val + 8) = next;
    Node* n = pos->next;
    if (n->color == 0)
        n->prev = val;
    Node* p = *(Node**)((char*)val + 4);
    *(Node**)((char*)pos + 4) = p;
    Node* h = *(Node**)((char*)this + 0x18);
    if (val == h->prev) {
        h->prev = pos;
        pos->next = val;
        val->prev = pos;
        return;
    }
    Node* q = *(Node**)((char*)val + 4);
    if (val == q->next) {
        q->next = pos;
        pos->next = val;
        val->prev = pos;
        return;
    }
    q->parent = pos;
    pos->next = val;
    val->prev = pos;
}
