// from server: 100% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct Count {
    void* vtbl; long use;
    void add_ref() { _InterlockedIncrement(&use); }
};
struct SP {
    void* px; Count* pn;
    SP(const SP& o) : px(o.px), pn(o.pn) { if (pn) pn->add_ref(); }
    ~SP();
};
struct Lock { void* p; Lock(SP s, int f); ~Lock(); };
struct Str { const char* c_str() const; };
extern const char* (Str::*g_c_str)() const;
inline const char* Str::c_str() const { return (this->*g_c_str)(); }
struct CString {
    void* p;
    CString(const char* s);
    void init(const char* s);
    ~CString();
};
extern void (CString::*g_init)(const char*);
inline CString::CString(const char* s) { (this->*g_init)(s); }
struct Obj {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21();
    char pad[0x84];
    Str name;
};
struct CValueItem {
    char pad[0x7c];
    SP sp;
    Obj* obj;
    CString getValue(int);
};
CString CValueItem::getValue(int) {
    Lock lock(sp, 1);
    Obj* o = obj;
    o->v21();
    return CString(o->name.c_str());
}
