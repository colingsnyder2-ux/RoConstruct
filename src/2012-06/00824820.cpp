// from server: 36% by atomic.potato
extern "C" void __stdcall sub_4015A0(int, int);
extern "C" void* __stdcall sub_770EB0();
extern "C" void* __stdcall sub_4E77F0();
extern "C" void __stdcall sub_6CB9E0(void*, int, int, int, int, int, int, int);
extern "C" void* __stdcall sub_98211A(int);

struct S {
    char pad0[0x28];
    void* field28;
    void* field2C;
    void method(int, int, int, int, int);
};

void S::method(int a1, int a2, int a3, int a4, int a5)
{
    sub_4015A0(0xe485fc, 0x770f10);
    void* edi = sub_770EB0();
    void* eax = sub_4E77F0();
    sub_6CB9E0(this, (int)eax, (int)edi, a1, a2, a3, a4, a5);
    field28 = edi;
    *(void**)this = (void*)0xbccbec;
    void* p = sub_98211A(0xc);
    if (p) {
        *(void**)p = (void*)0xbcc8dc;
        *((int*)p + 1) = a4;
        *((int*)p + 2) = a5;
    } else {
        p = 0;
    }
    field2C = p;
}
