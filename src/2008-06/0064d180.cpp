// from server: 100% by king_originala
struct Result {
    char padding[0x40];
    unsigned int state;
};

struct Node {
    virtual void slot0();
    virtual void slot1();
    virtual Result* getResult();

    char padding[0x18];
    void* first;
    void* second;
};

struct Pair {
    Pair();
    void* first;
    void* second;
};

struct Container {
    char padding[0x18];
    Pair insert(void* first, void* second);
};

extern "C" void __cdecl update(Node*, int);

struct S {
    char padding[0x10];
    Container container;
    unsigned int count;

    int lookup(Node*);
    void f(Node*);
};

void S::f(Node* node)
{
    int value = count > 1 ? lookup(node) : 0;
    update(node, value);
    container.insert(node->first, node->second);
    if (node->getResult())
        node->getResult()->state = 0;
}
