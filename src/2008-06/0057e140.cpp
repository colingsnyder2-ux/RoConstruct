// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Node {
    Node* next;
};

struct Object;

struct ObjectVTable {
    void* reserved[14];
    Node* (__thiscall* getNode)(Object*);
};

struct Object {
    ObjectVTable* vtable;
};

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    Object* object;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct List {
    unsigned int reserved;
    Node* first;
    Node* last;
};

void __cdecl clearBackpack(List* list, Shared value)
{
    Node* node = value.object->vtable->getNode(value.object);
    if (node) {
        if (!list->last)
            list->first = node;
        else
            list->last->next = node;
        list->last = node;
    }
}
