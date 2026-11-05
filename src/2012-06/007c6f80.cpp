// from server: 56% by atomic.potato
// roc 2012-06 007c6f80  unit: RBX::VRegion3int16::?$TypedPropertyDescriptor  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007c6f80

extern "C" int __cdecl sub_4015A0(const char*, const char*);
extern "C" int __cdecl sub_7712A0();
extern "C" int __cdecl sub_67F5B0(int*, int*);
extern "C" int __cdecl sub_76BEB0(int);

struct S {
};

int __cdecl f(int* a)
{
    char* p;
    if (*(unsigned int*)((char*)a + 0x18) < 0x10)
        p = (char*)a + 4;
    else
        p = *(char**)((char*)a + 4);

    sub_4015A0((const char*)0xE48620, (const char*)0x771300);
    int r = sub_7712A0();
    int tmp = (int)p;
    int v = sub_67F5B0(&tmp, &tmp);
    return sub_76BEB0(v);
}
