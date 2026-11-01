// from server: 100% by king_originala
struct Manager;

struct ManagerTable {
    void *slots[2];
    void (__thiscall *release)(Manager *);
};

struct Manager {
    ManagerTable *vtable;
};

extern Manager *manager;
extern void *objectTable[];
void __cdecl operator delete(void *);

struct S {
    void **vtable;
    unsigned char padding[20];
    unsigned long state;

    void cleanup();
    S *destroy(unsigned int flags);
};

S *S::destroy(unsigned int flags)
{
    vtable = objectTable;
    state = 0xC0000001UL;
    manager->vtable->release(manager);
    cleanup();
    if (flags & 1)
        operator delete(this);
    return this;
}
