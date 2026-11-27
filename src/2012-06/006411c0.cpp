// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S { int a0; int a4; int a8; int ac; int f10; int f14; int f18; int f1c; short s20; short s22; };
void init(S* p) {
    p->a0 = 0; p->a4 = -1; p->a8 = 0;
    p->f10 = -1; p->f14 = -1; p->f18 = -1; p->f1c = -1;
    p->s20 = 0; p->s22 = 0;
}
