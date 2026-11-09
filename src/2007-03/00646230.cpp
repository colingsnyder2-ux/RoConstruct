// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD
struct S {
    char pad[0x218];
    int field_218;
    void method_61e6d2();
    void method_645b50();
    void target(int, int, int);
};

void S::target(int a, int b, int c) {
    if (field_218 == 0) {
        field_218 = 1;
        method_61e6d2();
        method_645b50();
        (*(void (__thiscall **)(S *))(*(int *)this + 0x148))(this);
        field_218 = 0;
    }
}
