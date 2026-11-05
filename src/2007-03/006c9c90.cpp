// from server: 100% by tester
struct S {
    char* f();
};

char* S::f() {
    return reinterpret_cast<char*>(this) - 0x12c;
}