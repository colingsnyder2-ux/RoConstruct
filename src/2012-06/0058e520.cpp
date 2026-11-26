// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Type { bool isA(const void* t); };
struct B1 { char pad[0x1c]; };
struct B2 { char pad[0xc]; Type* type; };
struct D : B1, B2 {};
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
bool __stdcall f(D* d) { return cast(d) != 0; }
