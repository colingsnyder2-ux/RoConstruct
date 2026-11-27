// from server: 96% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct __declspec(dllimport) T { T(int); char pad[0x1c]; };
struct B { B(); int v; };
struct X : B { int m; T* p; X(int a); };
X::X(int a) { T* t = new T(a); m = 2; p = t; }
