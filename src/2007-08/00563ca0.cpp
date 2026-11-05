// from server: 41% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct SelectionContainer {
    int* begin;
    int* end;
};

struct Selection {
    char pad[0x104];
    SelectionContainer* container;
};

struct DataModel {
    char pad[0x14];
    Selection* getSelection(int);
};

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakRefCount;
};

struct GroupSelectionVerb {
    char pad[0x14];
    DataModel* dataModel;
    char pad2[8];
    RefCounted* ref;
    bool isEnabled() const;
};

bool GroupSelectionVerb::isEnabled() const
{
    Selection* sel = dataModel->getSelection(1);
    SelectionContainer* c = sel->container;
    int* b = c->begin;
    if (b == 0)
        return false;
    if ((c->end - b) == 0)
        return false;

    RefCounted* r = ref;
    RefCounted* local = r;
    Selection* sel2 = dataModel->getSelection(1);
    SelectionContainer* c2 = sel2->container;
    int* b2 = c2->begin;
    long count = (b2 == 0) ? 0 : (long)(c2->end - b2);
    bool result = count > 1;

    if (local != 0) {
        if (_InterlockedExchangeAdd(&local->refCount, -1) == 1) {
            void** vt = (void**)local->vptr;
            typedef void (__thiscall *Fn)(RefCounted*);
            ((Fn)vt[1])(local);
            if (_InterlockedExchangeAdd(&local->weakRefCount, -1) == 1) {
                ((Fn)vt[2])(local);
            }
        }
    }
    return result;
}
