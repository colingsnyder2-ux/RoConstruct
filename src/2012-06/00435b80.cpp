// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Base { void g(int a, int b, int c); };
struct CMainFrame : Base {
    void h(int a);
    void f(int a, int b, int c);
};
void CMainFrame::f(int a, int b, int c) { h(a); Base::g(a, b, c); }