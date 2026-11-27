// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct String {
    char b[28];
    __declspec(dllimport) String(const char*);
    __declspec(dllimport) const char* c_str() const;
};
struct Holder { char pad[0x44]; String name; };
struct CNameItem {
    char pad[0x7c];
    Holder* h;
    String f(int) const;
};
String CNameItem::f(int) const { volatile int z = 0; return String(h->name.c_str()); }