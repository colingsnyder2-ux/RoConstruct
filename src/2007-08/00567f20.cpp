// from server: 100% by colin
struct RootInstance {
    void* vtable;
    char pad[4];
    void* field_8;
    void* field_C;
    void* field_10;
    void func_00567f20();
};

extern "C" void __cdecl func_00567d60(void*, void*, void*, int);
extern "C" void __cdecl func_0062fc62(void*);

void RootInstance::func_00567f20()
{
    int arg;
    this->vtable = (void*)0x7a9804;
    char* esi = (char*)this + 4;
    void* p = *(void**)(esi + 4);
    if (p != 0) {
        void* edx = *(void**)(esi + 8);
        func_00567d60(p, edx, esi, arg);
        void* q = *(void**)(esi + 4);
        func_0062fc62(q);
    }
    *(void**)(esi + 4) = 0;
    *(void**)(esi + 8) = 0;
    *(void**)(esi + 0xc) = 0;
}
