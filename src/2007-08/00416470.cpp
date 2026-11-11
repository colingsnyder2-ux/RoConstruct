// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD

struct GUID;
struct ITypeInfo {
    virtual long __stdcall QueryInterface(const GUID&, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

class CComTypeInfoHolder
{
public:
    const GUID* m_pguid;
    const GUID* m_plibid;
    unsigned short m_wMajor;
    unsigned short m_wMinor;
    ITypeInfo* m_pInfo;

    long GetTypeInfo(unsigned int, unsigned long lcid, ITypeInfo** pptinfo)
    {
        return GetTI(lcid, pptinfo);
    }
    long GetTI(unsigned long lcid, ITypeInfo** ppInfo)
    {
        if (ppInfo == 0)
            return 0x80004003L;

        long hr = 0;
        if (m_pInfo == 0)
            hr = GetTI(lcid);
        *ppInfo = m_pInfo;
        if (m_pInfo != 0)
        {
            m_pInfo->AddRef();
            hr = 0;
        }
        return hr;
    }
    long GetTI(unsigned long lcid);
};

struct IDispatchImpl
{
    static CComTypeInfoHolder _tih;
    virtual long __stdcall GetTypeInfo(unsigned int itinfo, unsigned long lcid, ITypeInfo** pptinfo);
};

CComTypeInfoHolder IDispatchImpl::_tih;

long __stdcall IDispatchImpl::GetTypeInfo(unsigned int itinfo, unsigned long lcid, ITypeInfo** pptinfo)
{
    return _tih.GetTypeInfo(itinfo, lcid, pptinfo);
}
