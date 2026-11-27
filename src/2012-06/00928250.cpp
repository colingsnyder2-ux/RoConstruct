// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct T { void g(int,int,int); T* f(int a,int b); };
T* T::f(int a,int b){ g(a,b,100); return this; }
