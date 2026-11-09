// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
#pragma optimize("g", off)
struct T{void m();}; extern T G; void f(){G.m();}
