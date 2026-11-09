// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Node {
    virtual void slot0();
    virtual int type();
    unsigned int reserved;
    Node* next;
    void finish(void* arg);
};

struct World {
    unsigned char reserved[0xb8];
    Node* node;
    void finish(void* arg);
};

void World::finish(void* arg)
{
    Node* current = node;
    while (current->type() != 2)
        current = current->next;
    current->finish(arg);
}
