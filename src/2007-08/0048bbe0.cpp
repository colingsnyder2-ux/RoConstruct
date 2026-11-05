// from server: 49% by tester
struct ICreator {
    void* vtable;
};

struct Creator : ICreator {
    void* field4;
    void* field8;
    void* fieldC;
    Creator(void* arg, int unused);
};

extern "C" void* __cdecl operator_new(unsigned int size);

Creator::Creator(void* arg, int unused)
{
    this->vtable = 0;
    void* mem = operator_new(0x14);
    if (mem != 0) {
        *(int*)((char*)mem + 4) = 1;
        *(int*)((char*)mem + 8) = 1;
        *(void**)mem = (void*)0x79b054;
        *(void**)((char*)mem + 0xC) = arg;
    } else {
        mem = 0;
    }
    this->vtable = mem;
}
