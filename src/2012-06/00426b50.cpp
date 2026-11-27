// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Base { virtual void f(); char pad[0xe8]; Base(void* p); };
struct __declspec(novtable) I1 { virtual void a(); };
struct __declspec(novtable) I2 { virtual void b(); };
struct D : Base, I1, I2 { D(void* p); virtual void f(); virtual void a(); virtual void b(); };
D::D(void* p) : Base(p) {}