// from server: 100% by tester
struct S {
    void method_401ba0(int, int);
};

void S::method_401ba0(int a, int b) {
    int* p;
    if (a != 0) {
        p = (int*)(a - 0xc);
    } else {
        p = 0;
    }
    int* vt = (int*)*p;
    void (__stdcall *fn)(int*, void*, int) = (void (__stdcall *)(int*, void*, int))vt[0];
    fn(p, (void*)0x783be4, b);
}
