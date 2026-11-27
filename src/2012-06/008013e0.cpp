// from server: 78% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct String;
extern void (__thiscall *destroyString)(String*);
struct String { int pad0; char buf[16]; unsigned size; unsigned cap;
  __declspec(dllimport) String(const String&);
  ~String() { destroyString(this); } };struct T { void m(String*, int*, int*); };
struct Slot { void (T::*fn)(String*, int*, int*); char* obj; int adj; };
void f(Slot* s, String a1, int a2, int a3) { (((T*)(s->obj + s->adj))->*(s->fn))(&a1, &a2, &a3); }