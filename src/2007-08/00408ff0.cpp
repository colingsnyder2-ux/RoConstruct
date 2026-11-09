// from server: 22% by colin
// roc 2007-08 00408ff0  unit: VCApp::?$CComObject  size: 489 bytes

struct IUnknownLike {
    virtual int QueryInterface(void* riid, void** ppv) = 0;
    virtual unsigned long AddRef() = 0;
    virtual unsigned long Release() = 0;
};

struct IEnumLike : IUnknownLike {
    virtual int Next(unsigned long celt, void* rgelt, unsigned long* pceltFetched) = 0;
    virtual int Skip(unsigned long celt) = 0;
    virtual int Reset() = 0;
    virtual int Clone(IEnumLike** ppenum) = 0;
};

struct IItemLike : IUnknownLike {
    virtual int get_Name(void** pName) = 0;
    virtual int get_Value(void** pValue) = 0;
};

struct ICollectionLike : IUnknownLike {
    virtual int get_Count(long* pCount) = 0;
    virtual int get_Item(long index, void** ppItem) = 0;
    virtual int get__NewEnum(IUnknownLike** ppEnum) = 0;
};

struct VCApp_CComObject {
    int method(long a, long b);
};

int VCApp_CComObject::method(long a, long b)
{
    IUnknownLike* punk = 0;
    IEnumLike* penum = 0;
    IUnknownLike* punk2 = 0;
    IItemLike* pitem = 0;
    int result = -1;

    if (this == 0)
    {
        ICollectionLike* pcol = (ICollectionLike*)((char*)this - 0x14);
        punk = (IUnknownLike*)pcol;
        if (punk->QueryInterface((void*)0x784cf0, (void**)&punk) < 0)
            goto cleanup;
    }
    else
    {
        goto cleanup;
    }

    if (punk->QueryInterface((void*)0x7c4e2c, (void**)&penum) < 0)
        goto cleanup;

    if (penum->Next(1, &punk2, 0) < 0)
        goto cleanup;

    if (punk2->QueryInterface((void*)0x7c4e0c, (void**)&pitem) < 0)
        goto cleanup;

    result = pitem->get_Value((void**)&a);

cleanup:
    if (pitem != 0)
        pitem->Release();
    if (punk2 != 0)
        punk2->Release();
    if (penum != 0)
        penum->Release();
    if (punk != 0)
        punk->Release();
    return result;
}
