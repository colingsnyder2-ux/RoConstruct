// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>

// INFERRED: layouts reconstructed from the disassembly; real class names are unknown.
struct Item {
    virtual ~Item();
    virtual void onRelease();   // vtable slot 1, called with no args
};

struct Node {
    Item* item;   // +0
    Node* next;   // +4
};

struct Counted {
    virtual ~Counted();         // slot 0, called with flag 1 (scalar deleting dtor)
    volatile LONG refs;         // +4
    Node* head;                 // +8
};

struct Handle {
    Counted* p;
};

// INFERRED: this is an intrusive shared-pointer assignment operator
extern "C" Handle* __fastcall fn_004e60f0(Handle* self, int unusedEdx, Handle* other)
{
    Counted* nb = other->p;
    if (nb == self->p)
        return self;

    if (self->p) {
        if (InterlockedDecrement(&self->p->refs) == 0) {
            Node* n = self->p->head;
            while (n) {
                n->item->onRelease();
                Node* cur = n;
                n = n->next;
                delete cur;
            }
            if (self->p)
                delete self->p;
        }
        self->p = 0;
    }
    if (nb) {
        self->p = nb;
        InterlockedIncrement(&nb->refs);
    }
    return self;
}
