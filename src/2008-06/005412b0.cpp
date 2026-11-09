// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
#pragma optimize("", off)

typedef unsigned int size_t;
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct S;

struct Node {
    S* owner;
    Node* next;
    Node(S*, Node*);
};

struct Object {
    char padding[8];
    Node* head;
};

struct S {
    char padding[4];
    Object* object;
    void clear();
    void f(Object*);
};

void S::f(Object* value)
{
    clear();
    object = value;
    if (object != 0) {
        Node* node = new Node(this, object->head);
        object->head = node;
    }
}
