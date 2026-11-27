// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Q { char pad[0x54]; int v; };
struct P { char pad[0x54]; Q* q; };
struct Base { void g(int a, int b, int c); };
struct Q;
void helper(int, Q*);
struct CScriptEditor : Base {
    char pad[0x54 - 1];
    P* p;
    void f(int a, int b, int c);
};
void CScriptEditor::f(int a, int b, int c) {
    Base::g(a, b, c);
    if (a) helper(1, p->q);
}