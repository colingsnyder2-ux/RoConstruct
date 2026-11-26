// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ short v; unsigned char f(); }; unsigned char S::f(){ unsigned char r; if(v!=2) r=6; else r=4; return r; }
