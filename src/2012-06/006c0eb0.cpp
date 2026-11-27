// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Inner { virtual void v0(); virtual void v1(); virtual float get(int); };
struct Var { void reset(); int pad; int type; float f; };
struct Outer {
    char pad[0x28]; Inner* inner;
    void f(int q, char* d);
};void Outer::f(int q, char* d){ float r = inner->get(q); Var* v = (Var*)(d + 0x10); v->reset(); v->f = r; v->type = 7; }
