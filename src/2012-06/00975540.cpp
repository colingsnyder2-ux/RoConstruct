// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
void g(double*); double f(){ double d; g(&d); return d; }
