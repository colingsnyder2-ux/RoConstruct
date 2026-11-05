// from server: 47% by TrollStein
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    long refCount;
    long weakRefCount;
};

struct List {
    void* head;
    void* tail;
};

struct Container {
    virtual void* getObject();
};

struct Backpack {
    void __cdecl addObject(Container* c, RefCounted* r);
};

void Backpack::addObject(Container* c, RefCounted* r)
{
    void* obj = c->getObject();
    if (obj) {
        List* list = (List*)((char*)this + 4);
        if (list->tail) {
            *(void**)list->tail = obj;
        } else {
            list->head = obj;
        }
        list->tail = obj;
    }
    if (r) {
        if (_InterlockedExchangeAdd(&r->refCount, -1) == 1) {
            void** vt = r->vptr;
            ((void (__thiscall*)(RefCounted*))vt[1])(r);
            if (_InterlockedExchangeAdd(&r->weakRefCount, -1) == 1) {
                void** vt2 = r->vptr;
                ((void (__thiscall*)(RefCounted*))vt2[2])(r);
            }
        }
    }
}
