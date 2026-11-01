// from server: 100% by king_originala
extern "C" {
    extern long (__stdcall *InterlockedDecrement)(volatile long *);
    extern long (__stdcall *InterlockedIncrement)(volatile long *);
}
void __cdecl operator delete(void *);

struct Object {
    virtual ~Object();
    virtual void release();
};

struct Node {
    Object *object;
    Node *next;
};

struct Control {
    virtual ~Control();
    volatile long references;
    Node *head;
};

struct S {
    Control *control;
    S &operator=(const S &other);
};

S &S::operator=(const S &other)
{
    Control *incoming = other.control;
    if (incoming != control) {
        if (control) {
            if (InterlockedDecrement(&control->references) == 0) {
                Node *node = control->head;
                while (node) {
                    node->object->release();
                    Node *old = node;
                    node = node->next;
                    operator delete(old);
                }
                delete control;
            }
            control = 0;
        }
        if (incoming) {
            control = incoming;
            InterlockedIncrement(&incoming->references);
        }
    }
    return *this;
}
