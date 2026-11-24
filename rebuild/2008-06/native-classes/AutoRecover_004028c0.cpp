// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout of CComPolyObject<CAxHostWindow>: vptr at +0, m_dwRef at +4,
// virtual slot 3 (+0xc) is the deleting destructor (after QueryInterface/AddRef/Release).
struct PolyObj {
    virtual long __stdcall QueryInterface_(const void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef_();
    virtual unsigned long __stdcall Release_();
    virtual ~PolyObj();
    long m_dwRef;
};

// INFERRED: CComSingleThreadModel::Decrement works through a long* (hides the
// non-null knowledge of the object pointer so the delete keeps its null test).
static inline long Decrement(long* p)
{
    return --(*p);
}

extern "C" unsigned long __stdcall fn_004028c0(PolyObj* self)
{
    unsigned long l = (unsigned long)Decrement(&self->m_dwRef);
    if (l == 0)
        delete self;
    return l;
}
