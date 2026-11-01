// from server: 100% by colin
struct S {
    char* f();
};

char* S::f() {
    return reinterpret_cast<char*>(this) - 0x284;
}
