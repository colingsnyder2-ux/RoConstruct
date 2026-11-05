// from server: 100% by king_originala
typedef unsigned int size_t;
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct Node {
    char storage[36];
    Node(void*);
};

struct Member {
    void* storage;
    Member();
    ~Member();
};

struct Parent {
    void* first;
    Node* node;
    void* second;
    Parent(void*, Node*, void*);
    virtual ~Parent();
};

inline Parent::Parent(void* a, Node* n, void* b)
    : first(a), node(n), second(b)
{
}

struct S : Parent {
    Member member;
    S(void*, void*);
    virtual ~S();
};

S::S(void* a, void* b)
    : Parent(a, new Node(this), b), member()
{
}
