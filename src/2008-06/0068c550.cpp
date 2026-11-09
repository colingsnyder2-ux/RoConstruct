// from server: 100% by Cezant64gamejr
struct S {
    void f(char param);
};

void S::f(char param) {
    reinterpret_cast<char*>(this)[0x8b82] = param;
}
