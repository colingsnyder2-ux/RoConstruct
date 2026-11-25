// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" void* fn_006a0920(unsigned int size);

struct Local_006188e0_Base {};
struct Local_006188e0_Obj : virtual public Local_006188e0_Base {};

typedef int (Local_006188e0_Obj::*Local_006188e0_GetFn)() const;
typedef void (Local_006188e0_Obj::*Local_006188e0_SetFn)(int);

struct Local_006188e0_GetSet {
    virtual bool isReadOnly() const = 0;
    virtual bool isWriteOnly() const = 0;
    virtual int getValue(const void*) const = 0;
    virtual void setValue(void*, const int&) const = 0;
};

struct Local_006188e0_GetSetImpl : public Local_006188e0_GetSet {
    Local_006188e0_GetFn get;
    Local_006188e0_SetFn set;

    Local_006188e0_GetSetImpl(Local_006188e0_GetFn g, Local_006188e0_SetFn s)
        : Local_006188e0_GetSet(), get(g), set(s) {}

    static void* operator new(unsigned int sz) { return fn_006a0920(sz); }
    static void operator delete(void*) {}

    virtual bool isReadOnly() const { return false; }
    virtual bool isWriteOnly() const { return false; }
    virtual int getValue(const void* o) const { return (((const Local_006188e0_Obj*)o)->*get)(); }
    virtual void setValue(void* o, const int& v) const { (((Local_006188e0_Obj*)o)->*set)(v); }
};

struct Local_006188e0_AutoPtr {
    Local_006188e0_GetSet* _Myptr;
    Local_006188e0_AutoPtr* set(Local_006188e0_GetSet* p) { _Myptr = p; return this; }
};

extern "C" Local_006188e0_AutoPtr* fn_006188e0(Local_006188e0_AutoPtr* __restrict out, Local_006188e0_GetFn get, Local_006188e0_SetFn set)
{
    int volatile dummy = 0;
    return out->set(new Local_006188e0_GetSetImpl(get, set));
}
