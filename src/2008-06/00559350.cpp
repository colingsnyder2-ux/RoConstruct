// from server: 100% by EspClaude
// roc 2008-06 00559350  unit: RBX::VInstance::?$NonFactoryProduct  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00559350
//

struct Node {
    Node* next;
};

struct List {
    Node* first;
    Node* last;
    void add(Node* node)
    {
        if (!last)
            first = node;
        else
            last->next = node;
        last = node;
    }
};

struct Root {
    int reserved;
    List children;
    ~Root();
};

struct Result {
    char storage[28];
    ~Result();
};

extern Root* __cdecl makeRoot();
extern Result __cdecl convertRoot(Root*);
void __cdecl operator delete(void*);

struct Owner {
    Root* pointer;
    explicit Owner(Root* p);
    ~Owner();
};

inline Owner::Owner(Root* p)
    : pointer(p)
{
}

inline Owner::~Owner()
{
    delete pointer;
}

struct Instance {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual Node* makeNode();

    Result build();
};

Result Instance::build()
{
    Root* root = makeRoot();
    Node* node = makeNode();

    root->children.add(node);

    Owner owner(root);
    return convertRoot(root);
}
