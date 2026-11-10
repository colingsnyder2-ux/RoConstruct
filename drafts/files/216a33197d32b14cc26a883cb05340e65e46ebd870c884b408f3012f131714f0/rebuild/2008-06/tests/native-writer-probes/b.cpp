// native-flags: /O2 /EHsc /GS- /MD /DNDEBUG
struct E { ~E() {} };
struct A { __declspec(noinline) A(); __declspec(noinline) ~A(); };
void g();
void f() { E e; A a; g(); }
