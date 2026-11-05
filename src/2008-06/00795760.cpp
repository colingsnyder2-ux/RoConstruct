// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD
struct Sub {
    void Init();
};

struct Group {
    char pad0[0x20];
    Sub sub;
    char pad1[0x10];
    int field34;
    int field38;

    Group* Construct();
};

extern "C" void __fastcall BaseInit(Group* self);

Group* Group::Construct()
{
    BaseInit(this);
    *(void**)this = (void*)0x86b7fc;
    sub.Init();
    field34 = 0;
    field38 = 0;
    return this;
}
