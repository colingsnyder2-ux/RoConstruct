// from server: 80% by Xemicl
// roc-cl: 21022
// roc-flags: /O1 /Ob2 /Oy /GS- /EHsc /MD

struct F { void (__thiscall *fn)(void*, void*); char *obj; int off; int pad; int arg; };
void g(F **pp){ F *f=*pp; f->fn(f->obj+f->off, &f->arg); }
