// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S {
    int pad;
    int a; char b; char c; int d; int e; int f; int g;
    S* set(int x, int y);
};
S* S::set(int x, int y) {
    a = 0; b = 0; d = x; c = 3; e = y; f = -1; g = -1;
    return this;
}