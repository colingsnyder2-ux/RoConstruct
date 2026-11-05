// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
typedef struct _GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
} GUID;
struct __declspec(uuid("B196B286-BAB4-101A-B69C-00AA00341D07")) IConnectionPointX;
inline int InlineIsEqualGUID(const GUID& rguid1, const GUID& rguid2)
{
    return (
        ((unsigned long*)&rguid1)[0] == ((unsigned long*)&rguid2)[0] &&
        ((unsigned long*)&rguid1)[1] == ((unsigned long*)&rguid2)[1] &&
        ((unsigned long*)&rguid1)[2] == ((unsigned long*)&rguid2)[2] &&
        ((unsigned long*)&rguid1)[3] == ((unsigned long*)&rguid2)[3]);
}
inline int InlineIsEqualUnknown(const GUID& rguid1)
{
    return (
        ((unsigned long*)&rguid1)[0] == 0 &&
        ((unsigned long*)&rguid1)[1] == 0 &&
        ((unsigned long*)&rguid1)[2] == 0x000000C0 &&
        ((unsigned long*)&rguid1)[3] == 0x46000000);
}
class _ICPLocatorX {
public:
    virtual long __stdcall _LocCPQueryInterface(const GUID& riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
template <class T>
class IConnectionPointImplX : public _ICPLocatorX {
public:
    long __stdcall _LocCPQueryInterface(const GUID& riid, void** ppvObject)
    {
        if (ppvObject == 0)
            return 0x80004003L;
        *ppvObject = 0;
        if (InlineIsEqualGUID(riid, __uuidof(IConnectionPointX)) || InlineIsEqualUnknown(riid)) {
            *ppvObject = this;
            AddRef();
            return 0;
        } else
            return 0x80004002L;
    }
};
class CWorkspaceX;
template class IConnectionPointImplX<CWorkspaceX>;
