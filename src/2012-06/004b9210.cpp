// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct GUID_ { unsigned long a; unsigned short b, c; unsigned char d[8]; };
struct IUnknown_ {
    virtual long __stdcall QueryInterface(const GUID_&, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
extern "C" const GUID_ IID_Thing;
int __cdecl IsEqualGuid_(const GUID_& a, const GUID_& b);

long __stdcall GetInterface(IUnknown_* pUnk, const GUID_& riid, void** ppv) {
    if (!ppv) {
        return 0x80004003;
    }
    if (IsEqualGuid_(riid, IID_Thing)) {
        *ppv = pUnk;
        pUnk->AddRef();
        return 0;
    } else {
        *ppv = 0;
        return 0x80004002;
    }
}
