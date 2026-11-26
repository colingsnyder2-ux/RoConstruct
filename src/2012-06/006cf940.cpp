// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct O{ virtual void a();virtual void b();virtual void c();virtual void d();virtual void e();virtual void f();virtual void g();virtual void h(int); }; void f(int a,O* o){ o->h(a); }