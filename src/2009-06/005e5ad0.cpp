// from server: 33% by atomic.potato
extern "C" int __cdecl sub_5E48C0();
extern "C" int __cdecl sub_719AFB();

struct S {
    char pad[0x14];
    int f();
};

int S::f()
{
    int* p = (int*)0x00A4473C;
    if ((*p & 1) == 0) {
        *p |= 1;
        sub_5E48C0();
        *(int*)0x00A44728 = 0x008D5D28;
        sub_719AFB();
    }
    return 0x00A44728;
}
