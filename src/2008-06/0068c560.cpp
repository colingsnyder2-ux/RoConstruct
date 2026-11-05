// from server: 100% by Cezant64gamejr
struct S {
    void f(char value);
};

void S::f(char value) {
    *reinterpret_cast<char*>(reinterpret_cast<int>(this) + 0x8b81) = value;
}
