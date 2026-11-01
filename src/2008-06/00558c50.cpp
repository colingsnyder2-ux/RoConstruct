// from server: 100% by king_originala
void * __cdecl operator new(unsigned int);
void __cdecl operator delete(void *) throw();

extern void *defaultValue;
extern void *scopeKey;
extern void *parentKey;
extern void *lookupKey;
extern void *constructorKey;

void * __cdecl localScope();

struct S;

struct Ref {
    void *object;
    void *control;

    Ref(S *);
    Ref(const Ref &);
    ~Ref();
};

struct Interface {
    virtual void unused();
    virtual void *scope();
};

struct Node {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int reserved0;
    void *value;
    unsigned int d;
    unsigned int reserved1;
    unsigned int reserved2;
    unsigned int e;
    unsigned int f;

    Node();
    Node(void *, Ref);
    void setScope(void *, void *);
    void setParent(void *, Ref);
    void *find(void *);
};

__forceinline Node::Node()
{
    void *initialValue = defaultValue;
    a = 0;
    b = 0;
    c = 0;
    value = initialValue;
    d = 0;
    e = 0;
    f = 0;
}

struct S {
    char prefix[16];
    Interface interfacePart;
    char padding[280];
    bool enabled;

    Node *create();
    void update(void *);
    void attach(Node *);
};

Node *S::create()
{
    if (enabled) {
        void *scope = localScope();
        if (interfacePart.scope() != scope) {
            Node *p = new Node;
            p->setScope(scopeKey, interfacePart.scope());
            p->setParent(parentKey, Ref(this));
            update(p->find(lookupKey));
            attach(p);
            return p;
        }
    }

    return new Node(constructorKey, Ref(this));
}
