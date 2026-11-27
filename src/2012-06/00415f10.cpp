// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Sub {
    char d[4];
    __declspec(dllimport) int A(const char*);
    __declspec(dllimport) int B(int, int, int, int, int);
};
struct V {
    char pad[0x2b0];
    Sub s;
    void T(int);
    void invoke();
};
void V::invoke() {
    if (s.A(""))
        T(s.B(0, 0, 0, 0, 0));
}
