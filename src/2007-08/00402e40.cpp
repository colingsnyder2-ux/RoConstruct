// from server: 100% by tajop
struct _GUID { unsigned long Data1; unsigned short Data2; unsigned short Data3; unsigned char Data4[8]; };
struct _ATL_INTMAP_ENTRY;

extern "C" const _ATL_INTMAP_ENTRY _entries_784b88[];
long __stdcall AtlInternalQueryInterface(void* pThis, const _ATL_INTMAP_ENTRY* pEntries, const _GUID& iid, void** ppvObject);

struct CComContainedObject_Workspace {
    char m_pad[4];
};

struct CComAggObject_Workspace {
    virtual long __stdcall QueryInterface(const _GUID& iid, void** ppvObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    long m_dwRef;
    CComContainedObject_Workspace m_contained;
};

long __stdcall CComAggObject_Workspace::QueryInterface(const _GUID& iid, void** ppvObject)
{
    if (ppvObject == 0)
        return 0x80004003L;
    *ppvObject = 0;
    long hRes = 0;
    if (((unsigned long*)&iid)[0] == 0 &&
        ((unsigned long*)&iid)[1] == 0 &&
        ((unsigned long*)&iid)[2] == 0x000000C0 &&
        ((unsigned long*)&iid)[3] == 0x46000000)
    {
        *ppvObject = (void*)this;
        AddRef();
    }
    else
        hRes = AtlInternalQueryInterface(&m_contained, _entries_784b88, iid, ppvObject);
    return hRes;
}

