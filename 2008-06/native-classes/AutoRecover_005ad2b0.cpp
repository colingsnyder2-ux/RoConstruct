// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0080bc18[];
extern "C" char g_008344e0[];
extern "C" void* __cdecl fn_005ad200(void);

struct Local_005ad2b0_Mfp {
    int fn;
    int delta;
};

struct Local_005ad2b0_GetSet {
    void* vtbl;
    void* desc;
    int member;
    int pad;
    Local_005ad2b0_Mfp changed;
    Local_005ad2b0_GetSet(void* d, int m, Local_005ad2b0_Mfp c)
        : vtbl(g_008344e0), desc(d), member(m), changed(c) {}
};

struct Local_005ad2b0_Ref {
    Local_005ad2b0_GetSet* _Ref;
    explicit Local_005ad2b0_Ref(Local_005ad2b0_GetSet* p) : _Ref(p) {}
};

struct Local_005ad2b0_AutoPtr {
    Local_005ad2b0_GetSet* _Myptr;
    explicit Local_005ad2b0_AutoPtr(Local_005ad2b0_GetSet* p = 0) throw() : _Myptr(p) {}
    Local_005ad2b0_AutoPtr(Local_005ad2b0_AutoPtr& r) throw() : _Myptr(r._Myptr) { r._Myptr = 0; }
    Local_005ad2b0_AutoPtr(Local_005ad2b0_Ref r) throw() : _Myptr(r._Ref) {}
    operator Local_005ad2b0_Ref() throw() {
        Local_005ad2b0_GetSet* p = _Myptr;
        _Myptr = 0;
        return Local_005ad2b0_Ref(p);
    }
    ~Local_005ad2b0_AutoPtr() { delete _Myptr; }
    void reset(Local_005ad2b0_GetSet* p = 0) {
        if (p != _Myptr)
            delete _Myptr;
        _Myptr = p;
    }
};

struct Local_005ad2b0_Base {
    char pad[0x14];
    Local_005ad2b0_AutoPtr getset;
    Local_005ad2b0_Base(void* cd, const char* name, const char* category,
        Local_005ad2b0_AutoPtr gs, int flags);
    virtual ~Local_005ad2b0_Base();
};

struct Local_005ad2b0 : public Local_005ad2b0_Base {
    static void* operator new(unsigned int, void* p) throw() { return p; }
    __forceinline Local_005ad2b0(const char* name, const char* category,
        int member, Local_005ad2b0_Mfp changed, int flags)
        : Local_005ad2b0_Base(fn_005ad200(), name, category,
            Local_005ad2b0_AutoPtr(), flags)
    {
        *(void**)this = g_0080bc18;
        getset.reset(new Local_005ad2b0_GetSet(this, member, changed));
    }
};

extern "C" void* __fastcall fn_005ad2b0(
    void* self, int unusedEdx,
    const char* name, const char* category,
    int member, Local_005ad2b0_Mfp changed, int flags)
{
    __assume(self != 0);
    return new (self) Local_005ad2b0(name, category, member, changed, flags);
}
