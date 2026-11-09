// from server: 21% by atomic.potato
struct S {
    char pad[0x38];
    int field38;
    void __stdcall call_004b4f00(int);
    void __stdcall f(int, int);
};

void __stdcall S::f(int a, int b) {
    if (a) {
        call_004b4f00(b);
    } else {
        call_004b4f00(b);
    }
}
