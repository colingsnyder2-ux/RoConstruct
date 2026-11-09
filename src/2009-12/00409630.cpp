// from server: 39% by atomic.potato
extern "C" int __cdecl sub_643110();
extern "C" void __cdecl sub_662B90(void*, int, int, int, int, int, int);
extern "C" void __cdecl sub_7F385A(int);

struct VAuthoringSettings_FactoryProduct {
    void* vfptr;
    char pad[0x18];
    int field_1c;
    void* construct(int, int, int, int, int, int);
};

void* VAuthoringSettings_FactoryProduct::construct(int a1, int a2, int a3, int a4, int a5, int a6)
{
    int tmp;
    ++*(int*)0xb8feb8;
    tmp = 0;
    int r = sub_643110();
    sub_662B90(this, r, a1, a2, a3, a4, a5);
    this->vfptr = (void*)0x99fe4c;
    this->field_1c = a6;
    sub_7F385A(0);

    return this;
}
