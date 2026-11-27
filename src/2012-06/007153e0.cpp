// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct String;
extern void (__thiscall *destroyString)(String*);
struct String { int pad0; union { char buf[16]; char* p; }; unsigned size; unsigned cap;
  ~String() { destroyString(this); }
  const char* c_str() const { return cap >= 16 ? p : buf; } };
extern void __cdecl fn(const char*, int);
void __stdcall f(String s) { fn(s.c_str(), 2000); }