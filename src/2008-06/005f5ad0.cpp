// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD
struct S {
    char pad[0xb0];
    unsigned int field_0xb0;
    void f(unsigned char);
};

void S::f(unsigned char value) {
    unsigned int flags = field_0xb0;
    flags &= 0xffffffef;
    flags |= (value == 0) ? 0 : 0x10;
    field_0xb0 = flags;
}
