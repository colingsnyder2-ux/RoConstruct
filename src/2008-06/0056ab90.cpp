// from server: 100% by king_originala
struct Node;

struct Owner {
    char padding[20];
    Node* sentinel;
};

struct Proxy {
    Owner* owner;
};

struct Value {
    char padding[8];
    int flag;
};

struct Node {
    char padding[12];
    Value* value;
};

struct Iterator {
    void* owner;
    void* position;
    void* firstOwner;
    void* firstPosition;
    Proxy* proxy;
    Node* node;
    unsigned int unused;

    void advance();
};

struct Range {
    Iterator begin();
    Iterator* end(Iterator*);
};

struct S {
    char padding[8];
    Range range;

    bool f();
};

extern "C" void (__cdecl *invalid_parameter_noinfo)();

bool S::f()
{
    Iterator current = range.begin();
    void (__cdecl *check)() = invalid_parameter_noinfo;

    for (;;) {
        Iterator storage;
        Iterator* finish = range.end(&storage);

        if (!current.owner || current.owner != finish->owner)
            check();

        if (current.position == finish->position) {
            if (!current.owner || current.owner != current.firstOwner)
                check();

            if (current.position == current.firstPosition)
                return true;

            if (!current.proxy || current.proxy != finish->proxy)
                check();

            if (current.node == finish->node)
                return true;
        }

        if (!current.proxy)
            check();

        Owner* owner = current.proxy ? current.proxy->owner : 0;

        if (current.node == owner->sentinel)
            check();

        Value* value = current.node->value;
        if (value && value->flag)
            return false;

        current.advance();
    }
}
