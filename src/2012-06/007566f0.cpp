// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Type { bool isA(const void* t); };
struct B1 { char pad[0x1c]; };
struct B2 { char pad[0xc]; Type* type; };
struct D : B1, B2 {};
struct SP { D* px; void* pn; };
struct Vec { int pad; SP* first; SP* last; };
struct VecPtr {
    Vec* px;
    void* pn;
    Vec* operator->() const;
};
extern const void* __cdecl getType();
static inline D* cast(D* d)
{
    B2* b = d;
    if (b) {
        Type* t = b->type;
        if (t->isA(getType()))
            return static_cast<D*>(b);
    }
    return 0;
}
struct Container {
    char pad[0x3c];
    VecPtr children;
    D* find();
};
D* Container::find()
{
 if (children.px) {
 SP* end = children->last;
 for (SP* it = children->first; it != end; ++it) {
 D* d = it->px;
 if (d) { D* r = cast(d); if (r) return r; }
 }
 }
 return 0;
}
