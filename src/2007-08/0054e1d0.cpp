// from server: 100% by colin
struct S {
    void f(char);
};

void S::f(char a) {
    unsigned int v = *(unsigned int*)((char*)this + 0xb0);
    v &= 0xffffffef;
    v |= (a ? 0x10 : 0);
    *(unsigned int*)((char*)this + 0xb0) = v;
}
