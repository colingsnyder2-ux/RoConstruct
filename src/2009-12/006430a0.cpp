// from server: 25% by atomic.potato
extern "C" int __cdecl sub_641E40();
extern "C" int __cdecl sub_7F4929();

struct S {
    char pad[0x14];
};

int __cdecl sub_6430A0();

int __cdecl sub_6430A0()
{
    if (!(*(unsigned char*)0xB85C3C & 1)) {
        *(unsigned int*)0xB85C3C |= 1;
        sub_641E40();
        *(unsigned int*)0xB85C28 = 0x9CC918;
        sub_7F4929();
    }
    return 0;
}
