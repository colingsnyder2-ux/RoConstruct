// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct String;
extern void (__thiscall *destroyString)(String*);
struct String { char b[28]; ~String() { destroyString(this); } };
struct Obj { void g(String*, String*, int); };
struct S { char pad[0x27c]; Obj* o; void f(String a, String b); };
void S::f(String a, String b) { o->g(&a, &b, 1); }