// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Obj { void attach(int g); };
struct Vec { char pad[0x28]; Obj** data; int size; };
struct Parent { char pad[0xfc]; Vec* vec; };
struct CWrapperView {
    virtual ~CWrapperView();
    int pad;
    int index;
    char pad2[0x14-0xc];
    Parent* parent;
};
extern int gGlobal;
void __stdcall f(CWrapperView* v) {
    if (v->parent) {
        Vec* vec = v->parent->vec;
        int i = v->index;
        Obj* o = (i >= 0 && i < vec->size) ? vec->data[i] : 0;
        o->attach(gGlobal);
    }
    delete v;
}