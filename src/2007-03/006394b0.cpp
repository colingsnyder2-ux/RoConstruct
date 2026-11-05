// from server: 88% by atomic.potato
struct S {
    int f();
};

int S::f() {
    *(unsigned int*)((char*)this + 0xe0) |= 2;
    return 0;
}
