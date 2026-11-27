// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Arg { int type(); };
struct Target { void handle(Arg*); };
struct BallBlockContact {
    char pad[0x24];
    Target* target;
    int field28;
    void f(Arg* a);
};
void BallBlockContact::f(Arg* a) {
    if (a->type() == 10) field28 = 0;
    target->handle(a);
}
