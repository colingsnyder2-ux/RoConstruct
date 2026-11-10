// native-flags: /O2 /EHsc /GS- /MD /DNDEBUG
struct A { __declspec(noinline) A(); __declspec(noinline) ~A(); };
void g();
void f() { A a; try { g(); } catch (...) {} }
