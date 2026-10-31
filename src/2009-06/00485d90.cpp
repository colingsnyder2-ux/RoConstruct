// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Q { int v[5]; };
struct R {
    int c; int i4; float f8; Q q; int b;
};
struct RbxMeshPartAdapter {
    R func(int b, int c, const Q& d);
};
R RbxMeshPartAdapter::func(int b, int c, const Q& d)
{
    R r;
    r.c = c; r.i4 = 0; r.f8 = 0.0f; r.q = d; r.b = b;
    return r;
}
