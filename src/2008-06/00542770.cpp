// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
#pragma optimize("", off)
#pragma strict_gs_check(on)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S;
struct Node;

struct Object
{
    unsigned char reserved[8];
    Node* head;
};

struct Node
{
    S* owner;
    Node* next;

    Node(S*, Node*);
};

struct S
{
    unsigned int reserved;
    Object* object;

    void __thiscall reset();
    void __thiscall f(Object*);
};

void S::f(Object* value)
{
    reset();
    object = value;
    if (object)
    {
        Node* node = new Node(this, object->head);
        object->head = node;
    }
}
