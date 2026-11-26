// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct T { void set(int); };
struct S {
    char pad0[4];
    int field4;
    void (__thiscall *field8)(int);
    char padC[4];
    void method(int, int);
};
void S::method(int a, int b) {
    int edi;
    if (a) {
        edi = a - 0x1c;
    } else {
        edi = 0;
    }
    ((T*)(field4 + edi))->set(b);
    if (field8) {
        field8(edi + *(int*)((char*)this + 0xc));
    }
}