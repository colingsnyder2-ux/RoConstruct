// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /hotpatch
extern "C" __declspec(dllimport) void* __stdcall GetProcessHeap();
extern "C" __declspec(dllimport) int __stdcall HeapFree(void* hHeap, unsigned long dwFlags, void* lpMem);
struct IUnknown {
    virtual long __stdcall QueryInterface(const void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
class ActiveDocView {
public:
    virtual ~ActiveDocView();
    int m_pad;
    IUnknown* m_pUnknown;
    void* m_pData;
};
ActiveDocView::~ActiveDocView()
{
    if (m_pUnknown != 0)
        m_pUnknown->Release();
    if (m_pData != 0) {
        void* hHeap = GetProcessHeap();
        if (hHeap != 0)
            HeapFree(hHeap, 0, m_pData);
    }
}
