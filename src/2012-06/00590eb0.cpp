// from server: 97% by atomic.potato
struct S {
    char pad0[4];
    int field4;
    void (__thiscall *field8)(int);
    char padC[4];
    void method(int, int);
};

extern "C" void __stdcall sub_6a6210(int, int);

void S::method(int a, int b) {
    int edi;
    if (a) {
        edi = a - 0x1c;
    } else {
        edi = 0;
    }
    sub_6a6210(field4 + edi, b);
    if (field8) {
        field8(edi + *(int*)((char*)this + 0xc));
    }
}
