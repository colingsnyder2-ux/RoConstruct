// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct T{int a[10];}; struct A{ int p; T* arr; T* f(int i){ return &arr[i]; } }; T* h(A*a,int i){return a->f(i);}
