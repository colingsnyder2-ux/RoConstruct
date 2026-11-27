// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct String { char b[28]; __declspec(dllimport) String(const char*); __declspec(dllimport) ~String(); };
struct Base { Base(); virtual ~Base(); };
struct __declspec(novtable) I1 { virtual void a() = 0; char d[0x10]; };
struct __declspec(novtable) I2 { virtual void b() = 0; };
struct __declspec(novtable) I3 { virtual void c() = 0; };
struct D : Base, I1, I2, I3 {
    char pad[0xac - 0x20];
    String name;
    bool flag;
    D(const char* s);
    virtual void a(); virtual void b(); virtual void c();
};
D::D(const char* s) : name(s) { flag = false; }