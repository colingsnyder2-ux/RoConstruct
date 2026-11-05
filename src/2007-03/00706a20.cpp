// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD
struct S {
    void sub_7068C0(int);
    void sub_61E6D2();
    void f(int, int, int);
};

void S::f(int a, int b, int c) {
    sub_7068C0(1);
    sub_61E6D2();
}
