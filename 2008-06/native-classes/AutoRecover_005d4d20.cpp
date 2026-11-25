// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: BoundProp<TextureId, 1> constructor mirror for ShirtGraphic (005ad2b0 analog);
// no real header is included to avoid instantiating TypedPropertyDescriptor<T> inline bodies.
extern "C" char g_0083c4ec[];
extern "C" char g_0083c46c[];
extern "C" void* __cdecl fn_005c01d0(void);

struct Local_005d4d20_Mfp {
    int fn;
    int delta;
};

struct Local_005d4d20_GetSet {
    void* vtbl;
    void* desc;
    int member;
    int pad;
    Local_005d4d20_Mfp changed;
    Local_005d4d20_GetSet(void* d, int m, Local_005d4d20_Mfp c)
        : vtbl(g_0083c46c), desc(d), member(m), changed(c) {}
};

struct Local_005d4d20_Ref {
    Local_005d4d20_GetSet* _Ref;
    explicit Local_005d4d20_Ref(Local_005d4d20_GetSet* p) : _Ref(p) {}
};

struct Local_005d4d20_AutoPtr {
    Local_005d4d20_GetSet* _Myptr;
    explicit Local_005d4d20_AutoPtr(Local_005d4d20_GetSet* p = 0) throw() : _Myptr(p) {}
    Local_005d4d20_AutoPtr(Local_005d4d20_AutoPtr& r) throw() : _Myptr(r._Myptr) { r._Myptr = 0; }
    Local_005d4d20_AutoPtr(Local_005d4d20_Ref r) throw() : _Myptr(r._Ref) {}
    operator Local_005d4d20_Ref() throw() {
        Local_005d4d20_GetSet* p = _Myptr;
        _Myptr = 0;
        return Local_005d4d20_Ref(p);
    }
    ~Local_005d4d20_AutoPtr() {
        if (_Myptr != 0)
            delete _Myptr;
    }
    void reset(Local_005d4d20_GetSet* p = 0) {
        if (p != _Myptr) {
            if (_Myptr != 0)
                delete _Myptr;
        }
        _Myptr = p;
    }
};

struct Local_005d4d20_Base {
    char pad[0x14];
    Local_005d4d20_AutoPtr getset;
    Local_005d4d20_Base(void* cd, const char* name, const char* category,
        Local_005d4d20_AutoPtr gs, int flags);
    virtual ~Local_005d4d20_Base();
};

struct Local_005d4d20 : public Local_005d4d20_Base {
    static void* operator new(unsigned int, void* p) throw() { return p; }
    __forceinline Local_005d4d20(const char* name, const char* category,
        int member, Local_005d4d20_Mfp changed, int flags)
        : Local_005d4d20_Base(fn_005c01d0(), name, category,
            Local_005d4d20_AutoPtr(), flags)
    {
        *(void**)this = g_0083c4ec;
        getset.reset(new Local_005d4d20_GetSet(this, member, changed));
    }
};

extern "C" void* __fastcall fn_005d4d20(
    void* self, int unusedEdx,
    const char* name, const char* category,
    int member, Local_005d4d20_Mfp changed, int flags)
{
    __assume(self != 0);
    return new (self) Local_005d4d20(name, category, member, changed, flags);
}
