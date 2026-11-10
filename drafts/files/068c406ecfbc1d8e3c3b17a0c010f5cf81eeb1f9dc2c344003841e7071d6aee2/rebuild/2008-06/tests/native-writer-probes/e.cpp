// native-flags: /O2 /EHsc /GS- /MD /DNDEBUG
struct E { E() {} ~E() {} };
struct A { __declspec(noinline) A(); __declspec(noinline) ~A(); };
void g();
void f() { E(); A a; g(); }
