// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
void __stdcall g(float,char*); void __stdcall f(float x){ char c=0; g(x,&c); }
