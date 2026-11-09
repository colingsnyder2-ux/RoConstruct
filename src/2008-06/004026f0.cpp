// from server: 100% by tester
struct S {
    int f(int* p);
};

int S::f(int* p) {
    ++*(int*)((char*)p + 0x20);
    return *(int*)((char*)p + 0x20);
}