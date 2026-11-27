// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct String;
extern void (__thiscall *destroyString)(String*);
struct String {
    unsigned alloc;
    union { char buf[16]; char* ptr; } u;
    unsigned size; unsigned cap;
    __declspec(dllimport) String(const char*);
    ~String() { destroyString(this); }
    const char* c_str() const { return cap >= 16 ? u.ptr : u.buf; }
};
struct Impl { bool g(const String&); };
struct ContentProvider { char pad[0x9c]; Impl* impl; bool f(const String& name); };
bool ContentProvider::f(const String& name) { String tmp(name.c_str()); return impl->g(tmp); }