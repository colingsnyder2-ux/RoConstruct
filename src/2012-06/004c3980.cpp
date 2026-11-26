// from server: 75% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
void __stdcall g(int,int,int,int,int); void __stdcall f(int a,int b,int c,int d){ g(a,a,b,c,d); }
