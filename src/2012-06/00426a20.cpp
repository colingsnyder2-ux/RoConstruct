// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T{void m(void*,void*);};
void __stdcall f(T* p,void* b,void* a){((T*)((char*)p+4294967056))->m(b,a);}
