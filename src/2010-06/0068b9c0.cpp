// from server: 38% by atomic.potato
struct VInsertService_BoundYieldFuncDesc {
    char pad0[4];
    void* field4;
    void* invoke(void* a, void* b, void* c, void* d, void* e);
};

extern "C" void __stdcall sub_4B3F00(void* fn, void* arg);
extern "C" void __stdcall sub_66ED30();
extern "C" void __stdcall sub_68A140(void* a, void* b, void* c, void* d, void* e);

void* VInsertService_BoundYieldFuncDesc::invoke(void* a, void* b, void* c, void* d, void* e)
{
    void* local = 0;
    if (field4) {
        sub_4B3F00((void*)0x66ED30, local);
    }
    sub_68A140(a, b, c, d, e);

    return this;
}
