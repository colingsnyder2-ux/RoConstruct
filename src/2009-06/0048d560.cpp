// from server: 100% by why2
struct S {
    int field0;
    void method();
};

void S::method() {
    if (field0 == 1) {
        field0 = 0;
    }
    int* p = &field0 + 1;
    extern void __fastcall helper(int*);
    helper(p);
}
