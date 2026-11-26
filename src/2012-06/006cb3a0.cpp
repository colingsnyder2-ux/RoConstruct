// from server: 80% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
int* G();
void f(int* out) { *out = G()[1]; }
