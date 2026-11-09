// from server: 28% by atomic.potato
struct VCRenderSettingsItem_EnumPropDescriptor {
    void* vfptr;
    char pad0[0x18];
    void* field1c;
    void* field20;
    void* field24;
    void* construct(int, int, int, int, int, int, int);
};

extern "C" void __cdecl sub_401630(void*, void*);
extern "C" void* __cdecl sub_449530();
extern "C" void __cdecl sub_447c60();
extern "C" void __cdecl sub_662b90();
extern "C" void* __cdecl sub_444b50(void*);
extern "C" void __cdecl sub_7f385a(void*);

void* VCRenderSettingsItem_EnumPropDescriptor::construct(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    sub_401630((void*)0xb7ae28, (void*)0x449590);
    void* p = sub_449530();
    sub_447c60();
    sub_662b90();
    this->field1c = p;
    this->vfptr = (void*)0x9aa8bc;
    void* q = sub_444b50((void*)0);
    this->field20 = *(void**)q;
    *(void**)q = 0;
    sub_7f385a((void*)0);
    sub_401630((void*)0xb7ae28, (void*)0x449590);
    this->field24 = sub_449530();

    return this;
}
