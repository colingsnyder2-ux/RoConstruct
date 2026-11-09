// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct A{int** method();}; extern "C" A* __stdcall create(void*);
struct S{int* func();}; int* S::func(){return *(((A*)((char*)create(this)+0x54))->method());}
