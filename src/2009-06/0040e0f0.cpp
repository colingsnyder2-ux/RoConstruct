// from server: 100% by why2
struct S {
    int f(int* p);
};

int S::f(int* p) {
    ++*(int*)((char*)p + 0x18);
    return *(int*)((char*)p + 0x18);
}
