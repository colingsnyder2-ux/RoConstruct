// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct Z { char p[0x20]; char* y; };
struct Y { char p[0x28]; Z* x; };
struct M { char pad[0x28]; char* a; char* f(); };
char* M::f(){ char* p=a; Y* q = p ? (Y*)(p-8) : 0; char* y = q->x->y; return y ? y-8 : 0; }
