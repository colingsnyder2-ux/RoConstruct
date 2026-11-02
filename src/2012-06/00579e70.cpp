// from server: 100% by tajop
struct S {
    char pad[0x1c];
    void* first;
    void* last;
    void* end;
    void f();
};

void S::f() {
    if (first)
        operator delete(first);
    first = 0;
    last = 0;
    end = 0;
}
