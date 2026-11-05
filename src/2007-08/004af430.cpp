// from server: 46% by colin
struct ICreator {
    void* vtable;
};

struct Creator : ICreator {
    Creator(int arg);
};

extern "C" void* __cdecl operator_new(unsigned int size);

void* g_alloc;

Creator::Creator(int arg)
{
    this->vtable = 0;
    void* p = operator_new(0x14);
    if (p) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)p = (void*)0x79d8d0;
        *(int*)((char*)p + 0xc) = arg;
    } else {
        p = 0;
    }
    this->vtable = p;
}
