// from server: 93% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Obj { void rel(); };
struct Named { int pad; std::string name; };
void use(const char*, int);
struct T {
  virtual Named* v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
  virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
  char pad[0x1c]; int x20; char pad2[0x58]; Obj* o; char pad3[0x1c]; bool flag;
  int f(int);
};
int T::f(int) { if (flag) { o->rel(); o = 0; flag = false; use(v0()->name.c_str(), x20); } v14(); return 0; }
