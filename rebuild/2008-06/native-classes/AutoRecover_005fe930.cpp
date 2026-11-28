// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: PropDescriptor constructor (12-byte MFPs, auto_ptr<GetSet> return from getset);
// no real header is included to avoid inlining TypedPropertyDescriptor<T> ctor.
void __cdecl operator delete(void*) throw();
extern "C" char g_00841b18[];
extern "C" void* __cdecl fn_005c3810(void);

struct Local_005fe930_Mfp {
    int a, b, c;
};

struct Local_005fe930_Ref {
    int* _Ref;
    explicit Local_005fe930_Ref(int* p) : _Ref(p) {}
};

struct Local_005fe930_AutoPtr {
    int* _Myptr;
    explicit Local_005fe930_AutoPtr(int* p = 0) throw() : _Myptr(p) {}
    Local_005fe930_AutoPtr(Local_005fe930_AutoPtr& r) throw() : _Myptr(r._Myptr) { r._Myptr = 0; }
    Local_005fe930_AutoPtr(Local_005fe930_Ref r) throw() : _Myptr(r._Ref) {}
    operator Local_005fe930_Ref() throw() {
        int* p = _Myptr;
        _Myptr = 0;
        return Local_005fe930_Ref(p);
    }
    ~Local_005fe930_AutoPtr() {
        if (_Myptr != 0)
            delete _Myptr;
    }
};

// INFERRED: non-POD return prevents extern "C" in MSVC (C2526); C++ __cdecl matches hidden-ret ABI.
Local_005fe930_AutoPtr __cdecl fn_005fdd50(Local_005fe930_Mfp getter, Local_005fe930_Mfp setter);

struct Local_005fe930_Base {
    void init(void* cd, const char* name, const char* category,
        Local_005fe930_AutoPtr gs, int flags);
};

extern "C" void* __fastcall fn_005fe930(
    Local_005fe930_Base* self, int unusedEdx,
    const char* name, const char* category,
    Local_005fe930_Mfp getter, Local_005fe930_Mfp setter,
    int flags)
{
    self->init(fn_005c3810(), name, category, fn_005fdd50(getter, setter), flags);
    *(void**)self = g_00841b18;
    return self;
}
