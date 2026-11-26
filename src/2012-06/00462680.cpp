// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
void append(int, const char*);
extern const char s1[], s2[], s3[];
struct A { char pad[0x80]; bool b80, b81, b82; };
struct B { char pad[4]; bool b4, b5; };
struct RBXImage {
    int field_0;
    void func(A* a, B* b);
};
// The two "override or default" tests are inlined helpers; that is what gives
// the second argument a callee-saved register ahead of `this`.
inline bool h1(A* a, B* b) { if (a && a->b81) return true; return b->b4; }
inline bool h2(A* a, B* b) { if (a && a->b82) return true; return b->b5; }
void RBXImage::func(A* a, B* b) {
    if (a && !a->b80) append(field_0, s1);
    if (h1(a, b)) append(field_0, s2);
    if (h2(a, b)) append(field_0, s3);
}