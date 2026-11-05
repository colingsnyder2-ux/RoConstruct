// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct P3 { char pad[0x1d8]; void* value; };
struct P2 { char pad[0x20c]; P3* p; };
struct Obj { char pad[0xc]; P2* p; bool f(); };
struct C {};
extern "C" void* helper(void*);
extern C c;
typedef bool (__thiscall *Fn)(C*,void*);
extern Fn slot;
bool Obj::f(){ void* x=p->p->value; if(x){ x=helper(x); return slot(&c,x); } return false; }
