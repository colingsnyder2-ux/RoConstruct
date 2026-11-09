// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// from server: 81% by king_originala
struct Target {
    void f();
};

struct Link {
    char padding[0x24];
    Target* volatile target;
};

struct CRobloxModule {
    char padding[0x58];
    Link* volatile link;
    void f();
};

void CRobloxModule::f()
{
    Link* lnk = link;
    lnk->target->f();
}
