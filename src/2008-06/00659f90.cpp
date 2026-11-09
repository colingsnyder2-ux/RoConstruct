// from server: 100% by king_originala
extern "C" void* __cdecl allocate(unsigned int);

struct Key {
    unsigned int a, b, c;
};

struct Node {
    char padding[28];
    Key key;
    Node* next;
};

struct PoolNode {
    unsigned int unused;
    PoolNode* next;
    unsigned int reserved[2];
    unsigned int value;
    Key key;
    unsigned short kind;
    unsigned short padding;
    Node* node;
};

struct S {
    char padding[108];
    PoolNode* freeSmall;
    PoolNode* freeLarge;

    Node* find(unsigned int, unsigned int, const Key*);
    Node* create(unsigned int, unsigned int, const Key*);
    PoolNode* f(unsigned int, unsigned int, const Key*);
};

PoolNode* S::f(unsigned int kind, unsigned int value, const Key* key)
{
    if (kind == 0) {
        PoolNode* p = freeSmall;
        if (p) {
            freeSmall = p->next;
            p->value = value;
            p->key = *key;
            return p;
        }

        p = static_cast<PoolNode*>(allocate(36));
        if (p) {
            p->key.a = 0;
            p->key.b = 0;
            p->key.c = 0;
            p->kind = 0;
            return p;
        }
        return 0;
    }

    PoolNode* p = freeLarge;
    if (p) {
        freeLarge = p->next;
        p->kind = static_cast<unsigned short>(kind);
    } else {
        PoolNode* allocated = static_cast<PoolNode*>(allocate(40));
        if (allocated) {
            allocated->key.a = 0;
            allocated->key.b = 0;
            allocated->key.c = 0;
            allocated->kind = static_cast<unsigned short>(kind);
        } else {
            allocated = 0;
        }
        p = allocated;
    }

    p->value = value;
    p->key = *key;
    p->node = find(kind, value, key);
    if (!p->node)
        p->node = create(kind, value, key);
    ++reinterpret_cast<unsigned int*>(p->node)[5];
    return p;
}
