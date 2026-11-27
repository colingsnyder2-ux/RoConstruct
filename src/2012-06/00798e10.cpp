// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V3{float x,y,z;};
struct Obj { char pad[0x24]; V3 v; void base(const Obj*); void init(); };
struct Item { Obj* get(); };
struct Cat { Item* find(int); };
struct H { char pad[0x2d0]; Obj* f(Obj* p); };
Obj* H::f(Obj* p)
{
    Item* it = ((Cat*)((char*)this - 0x2d0))->find(1);
    if (it) {
        Obj* src = it->get();
        p->base(src);
        p->v = src->v;
        return p;
    }
    p->init();
    return p;
}
