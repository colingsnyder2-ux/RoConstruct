// from server: 96% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct String;
extern void (__thiscall *destroyString)(String*);
struct String { int pad0; char buf[16]; unsigned size; unsigned cap;
  __declspec(dllimport) String(const String&);
  ~String() { destroyString(this); } };struct Y { int a; };
struct X { char pad[8]; Y y; };
extern void __stdcall g(Y*, String);
void f(X* x, String s) { g(&x->y, s); }