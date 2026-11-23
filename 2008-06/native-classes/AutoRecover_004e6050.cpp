// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>
#include <new>

// INFERRED: layout from disassembly; intrusive refcounted body with node list at +8.
struct NodeItem {
    virtual void slot0();
    virtual void slot1();
};
struct Node {
    NodeItem* data;
    Node* next;
};
struct Body {
    virtual ~Body();
    volatile LONG refs;
    Node* head;
};
struct BodyRef4 {
    Body* p[4];
};

extern "C" BodyRef4* __fastcall fn_004e6050(BodyRef4* self, int unusedEdx, BodyRef4* src)
{
    for (int i = 0; i < 4; ++i) {
        Body* n = src->p[i];
        if (n == self->p[i])
            continue;
        if (self->p[i]) {
            if (InterlockedDecrement(&self->p[i]->refs) == 0) {
                Node* node = self->p[i]->head;
                while (node) {
                    node->data->slot1();
                    Node* cur = node;
                    node = node->next;
                    ::operator delete(cur);
                }
                if (self->p[i])
                    delete self->p[i];
            }
            self->p[i] = 0;
        }
        if (n) {
            self->p[i] = n;
            InterlockedIncrement(&n->refs);
        }
    }
    return self;
}
