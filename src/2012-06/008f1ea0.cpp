// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
bool g1(int, int, int, int, float);
char g2(int,int,int,int,float);
bool f(int a, int b, int c, int d, float e) {
    if (g1(a,b,c,d,e)) return true; return g2(a,b,c,d,e);
}