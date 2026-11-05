// from server: 100% by nuck16
// roc 2009-12 00682a00  (same-shape propagation from exact 0040bbb0)

void __fastcall sub_637b00(void*);
void __cdecl sub_7f385a(void*);

struct S {
    void* vf0;
    void* vf4;
    char gap_8[0x10];
    void* vf18;
    void* vf1c;
    void* destroy(unsigned int flags);
};

void* S::destroy(unsigned int flags) {
    vf0 = (void*)0x9a01a4;
    vf4 = (void*)0x9a019c;
    vf18 = (void*)0x9a0190;
    vf1c = (void*)0x9a0188;
    sub_637b00(this);
    if (flags & 1) {
        sub_7f385a(this);
    }
    return this;
}
