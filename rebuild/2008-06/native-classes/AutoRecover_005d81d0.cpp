// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" void* fn_006a0920(unsigned int size);

struct Local_005d81d0_Base {};
struct Local_005d81d0_Obj : virtual public Local_005d81d0_Base {};

typedef int (Local_005d81d0_Obj::*Local_005d81d0_GetFn)() const;
typedef void (Local_005d81d0_Obj::*Local_005d81d0_SetFn)(int);

struct Local_005d81d0_GetSet {
    virtual bool isReadOnly() const = 0;
    virtual bool isWriteOnly() const = 0;
    virtual int getValue(const void*) const = 0;
    virtual void setValue(void*, const int&) const = 0;
};

struct Local_005d81d0_GetSetImpl : public Local_005d81d0_GetSet {
    Local_005d81d0_GetFn get;
    Local_005d81d0_SetFn set;

    Local_005d81d0_GetSetImpl(Local_005d81d0_GetFn g, Local_005d81d0_SetFn s)
        : Local_005d81d0_GetSet(), get(g), set(s) {}

    static void* operator new(unsigned int sz) { return fn_006a0920(sz); }
    static void operator delete(void*) {}

    virtual bool isReadOnly() const { return false; }
    virtual bool isWriteOnly() const { return false; }
    virtual int getValue(const void* o) const { return (((const Local_005d81d0_Obj*)o)->*get)(); }
    virtual void setValue(void* o, const int& v) const { (((Local_005d81d0_Obj*)o)->*set)(v); }
};

struct Local_005d81d0_AutoPtr {
    Local_005d81d0_GetSet* _Myptr;
    Local_005d81d0_AutoPtr* set(Local_005d81d0_GetSet* p) { _Myptr = p; return this; }
};

extern "C" Local_005d81d0_AutoPtr* fn_005d81d0(Local_005d81d0_AutoPtr* __restrict out, Local_005d81d0_GetFn get, Local_005d81d0_SetFn set)
{
    int volatile dummy = 0;
    return out->set(new Local_005d81d0_GetSetImpl(get, set));
}
