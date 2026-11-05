// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#pragma optimize("g", off)
struct T{void m();}; extern T G; extern "C" void tail(void*);
void f(){G.m(); tail((void*)0x7fc640);}
