// from server: 100% by king_originala
#pragma optimize("", off)
struct S {
    void* pointer;
    bool f();
};

bool S::f() {
    return pointer == 0;
}
