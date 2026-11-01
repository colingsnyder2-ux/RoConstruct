// from server: 100% by colin
struct S {
    char pad[0xf0];
    int* field;
    int f();
};

int S::f() {
    int* p = field;
    if (p)
        return **(int**)((char*)p - 0xc);
    return 0;
}
