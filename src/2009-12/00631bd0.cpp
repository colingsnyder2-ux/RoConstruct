// from server: 41% by atomic.potato
struct RBX_VDebugSettings_GlobalSettingsItem {
    void* vfptr;
    char pad_04[0x18];
    int field_1c;
    int field_20;
    int field_24;
    void* construct(int, int, int, int, int, int, int, int);
};

extern "C" void __cdecl sub_401630(int, int);
extern "C" int __cdecl sub_630b60();
extern "C" int __cdecl sub_62ed80();
extern "C" void __cdecl sub_662b90(int, int, int, int, int, int, int, int);
extern "C" int* __cdecl sub_62cd40(int*);
extern "C" void __cdecl sub_7f385a(int);

void* RBX_VDebugSettings_GlobalSettingsItem::construct(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    sub_401630(0xb848d0, 0x630bc0);
    int edi = sub_630b60();
    int eax = sub_62ed80();
    sub_662b90(a1, a2, a3, a4, a5, a6, a7, a8);
    this->field_1c = edi;
    this->vfptr = (void*)0x9cb82c;
    int tmp;
    sub_62cd40(&tmp);
    this->field_20 = tmp;
    sub_7f385a(a8);
    sub_401630(0xb848d0, 0x630bc0);
    this->field_24 = sub_630b60();

    return this;
}
