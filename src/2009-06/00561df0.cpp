// from server: 32% by atomic.potato
struct S {
    char pad0[0x80];
    int field80;
    char pad84[0x44];
    int f(int);
};

extern "C" void __stdcall sub_5aa590();
extern "C" void* __cdecl sub_718a38(unsigned int);
extern "C" void __stdcall sub_560eb0();
extern "C" void __stdcall sub_560d90();
extern "C" void __stdcall sub_444d80();
extern "C" void __stdcall sub_5546e0();
extern "C" void __stdcall sub_555920();
extern "C" void __stdcall sub_485a00();
extern "C" int __stdcall InterlockedIncrement(int*);
extern "C" int __stdcall InterlockedDecrement(int*);

int S::f(int)
{
    sub_5aa590();
    *(int*)this = 0x8ca73c;
    field80 = 3;
    void* p = sub_718a38(0x24);
    if (p) {
        sub_560eb0();
    } else {
        p = 0;
    }
    int* q = 0;
    if (p) {
        q = (int*)p;
        InterlockedIncrement((int*)p + 1);
    }
    sub_560d90();
    if (q) {
        if (InterlockedDecrement(q + 1) != 0) {
            sub_444d80();
        }
    }
    return 0;
}
