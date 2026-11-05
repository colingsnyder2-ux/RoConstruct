// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

inline void* __cdecl operator new(size_t, void* p) { return p; }
inline void __cdecl operator delete(void*, void*) {}

struct Value {
    char data[60];
    Value(const Value&);
};

struct Node {
    Node* next;
    Node* prev;
    Value value;
};

template<class T>
inline void construct(T* p, const T& value)
{
    new (p) T(value);
}

Node* __stdcall make_node(Node* next, Node* prev, const Value& value)
{
    Node* p = static_cast<Node*>(operator new(sizeof(Node)));
    try {
        construct(&p->next, next);
        construct(&p->prev, prev);
        construct(&p->value, value);
    } catch (...) {
        operator delete(p);
        throw;
    }
    return p;
}
