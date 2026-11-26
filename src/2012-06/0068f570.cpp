// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
void __stdcall g(void*);
void fn();
void f(){ void* x = (void*)fn; g(&x); }
