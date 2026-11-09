// from server: 100% by tajop

// NOT COMPILED: this repair hasn't been built or diffed, so its score is unknown.
// Correction: my last note was wrong to say a function pointer can't replace the compiler-generated string calls.
// Inline Str_0071af20 special members can call through extern pointers, reproducing the indirect calls without a DLL import declaration.
// The instruction ordering and jump offset differences may or may not resolve with this change.
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)
struct Str_0071af20 {
    Str_0071af20(const Str_0071af20& o);
    ~Str_0071af20();
    char m_buf[0x1c];
};
extern void (Str_0071af20::*g_strCopy_0071af20)(const Str_0071af20&);
extern void (Str_0071af20::*g_strDtor_0071af20)();
inline Str_0071af20::Str_0071af20(const Str_0071af20& o)
{
    (this->*g_strCopy_0071af20)(o);
}
inline Str_0071af20::~Str_0071af20()
{
    (this->*g_strDtor_0071af20)();
}
struct Attr_0071af20 {
    int m_flags;
};
struct Counted_0071af20 {
    virtual ~Counted_0071af20();
    virtual void dispose();
    virtual void destroy();
    long m_use;
    long m_weak;
    void weak_add_ref()
    {
        _InterlockedIncrement(&m_weak);
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&m_weak) == 0)
            destroy();
    }
};
struct WeakCount_0071af20 {
    Counted_0071af20* pi;
    WeakCount_0071af20(const WeakCount_0071af20& o) : pi(o.pi)
    {
        if (pi != 0)
            pi->weak_add_ref();
    }
    ~WeakCount_0071af20()
    {
        if (pi != 0)
            pi->weak_release();
    }
};
struct Weak_0071af20 {
    void* px;
    WeakCount_0071af20 pn;
};
struct Base_0071af20 {
    Base_0071af20(Weak_0071af20 w, Str_0071af20 s, Attr_0071af20 flags);
    char m_pad[0x28];
};
struct Desc_0071af20 : Base_0071af20 {
    Desc_0071af20(Weak_0071af20 w, Str_0071af20 s, Attr_0071af20 flags, bool b);
    bool m_b;
};
Desc_0071af20::Desc_0071af20(Weak_0071af20 w, Str_0071af20 s, Attr_0071af20 flags, bool b)
    : Base_0071af20(w, s, flags), m_b(b)
{
}
