// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* __stdcall GetProcessHeap();
extern "C" __declspec(dllimport) int __stdcall HeapDestroy(void*);
struct __declspec(novtable) IAtlMemMgr {
    virtual void* Allocate(unsigned int n) = 0;
    virtual void Free(void* p) = 0;
    virtual void* Reallocate(void* p, unsigned int n) = 0;
    virtual unsigned int GetSize(void* p) = 0;
};
class CWin32Heap : public IAtlMemMgr {
public:
    CWin32Heap(void* hHeap) throw() : m_hHeap(hHeap), m_bOwnHeap(false) {}
    ~CWin32Heap() throw() { if (m_bOwnHeap && (m_hHeap != 0)) HeapDestroy(m_hHeap); }
    virtual void* Allocate(unsigned int n);
    virtual void Free(void* p);
    virtual void* Reallocate(void* p, unsigned int n);
    virtual unsigned int GetSize(void* p);
    void* m_hHeap;
    bool m_bOwnHeap;
};
CWin32Heap g_heap(GetProcessHeap());
