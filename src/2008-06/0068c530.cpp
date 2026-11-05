// from server: 100% by Cezant64gamejr
struct S {
    void f(char value);
};

void S::f(char value) {
    ((char*)((char*)this + 0x4324))[0] = value;
}
