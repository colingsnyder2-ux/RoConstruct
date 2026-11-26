// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
__declspec(dllimport) int g(int,int); struct T{int a,b;}; int f(T*a,T*b){ return g(a->b,b->b); }
