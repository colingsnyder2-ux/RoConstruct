// from server: 51% by colin
struct ICreator {
    void* vtable;
    int refcount1;
    int refcount2;
    void* arg;
};

struct Creator : ICreator {
    Creator(void* arg);
};

extern "C" void* __cdecl operator_new(unsigned int size);

Creator::Creator(void* arg)
{
    this->vtable = 0;
    void* mem = operator_new(0x14);
    if (mem) {
        ICreator* p = (ICreator*)mem;
        p->refcount1 = 1;
        p->refcount2 = 1;
        p->vtable = (void*)0x79b000;
        p->arg = arg;
        this->vtable = (void*)p;
    } else {
        this->vtable = 0;
    }
}
