// native-flags: /O2 /EHsc /GS- /MD /DNDEBUG
struct A { __declspec(noinline) A(); __declspec(noinline) ~A() throw(...); };
void g();
void f() { A a; g(); }
