// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)
struct Cnt {
    virtual ~Cnt(); virtual void dispose(); virtual void destroy();
    long use; long weak;
    void weak_release() { if (_InterlockedDecrement(&weak) == 0) destroy(); }
    void release() { if (_InterlockedDecrement(&use) == 0) { dispose(); weak_release(); } }
};
struct SP {
    void* px; Cnt* pn;
    ~SP() { if (pn) pn->release(); }
};
struct Type;
const Type& getType();
struct Holder { void assign(const SP&); };
struct Value {
    const Type* type; Holder h;
    void set(const SP& s) { type = &getType(); h.assign(s); }
};
struct A { int a; }; struct B { int b; };
struct Players : A, B { SP get(); };
void call(Players* o, SP (Players::*pmf)(), Value& v)
{
    v.set((o->*pmf)());
}
