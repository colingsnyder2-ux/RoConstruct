// from server: 55% by atomic.potato
struct PartInstance {
    void* vtable;
    char pad[4];
    int field8;
    int fieldc;
    int field10;
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl op_delete(void* p);

void PartInstance_GetSetImpl(PartInstance** out, int a, int b, int c)
{
    PartInstance* p = (PartInstance*)operator_new(0x18);
    if (p != 0) {
        p->vtable = (void*)0xa36570;
        p->field8 = a;
        p->fieldc = b;
        p->field10 = c;
    } else {
        p = 0;
    }
    *out = p;
    op_delete(0);
}
