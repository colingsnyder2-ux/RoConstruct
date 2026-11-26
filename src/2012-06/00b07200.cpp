// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Functionality { bool a; bool b; Functionality() : a(false), b(false) {} };
struct Sig { int v; Sig() : v(0) {} };
struct Holder { Functionality f; int x; int y; Holder() : x(0), y(0) {} };
struct Base {
    Base(int offset, const char* name, const char* a1, const char* a2, const char* a3, int z, Functionality f, Sig s);
    virtual ~Base();
    char pad[0x30];
    int f1; int f2;
};
struct Derived : Base {
    Derived() : Base(0x94, "InsertRequestAssetVersion", "key", "assetVersionId", "userId", 0, Holder().f, Sig()) { f1 = 0; f2 = 0; }
    virtual ~Derived() {}
};
static Derived desc;
