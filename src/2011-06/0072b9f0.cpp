// from server: 23% by atomic.potato
struct S {
    int f(int, int);
};

extern "C" void __stdcall sub_40AB90();
extern "C" void __stdcall sub_40D970();
extern "C" void __stdcall sub_72B0C0();

int S::f(int a, int b) {
    int v = *(int*)this;
    if (v == 0) {
        sub_40AB90();
        sub_40D970();
    }
    int r;
    ((void (__stdcall*)(int, int, int, int*))0)(0, 0, 0, &r);
    sub_72B0C0();
    return 0;
}
