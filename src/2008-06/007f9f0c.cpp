// from server: 100% by tester
#include <stddef.h>

typedef void* HANDLE;
extern "C" __declspec(dllimport) HANDLE __stdcall GetProcessHeap();
extern "C" __declspec(dllimport) int __stdcall HeapDestroy(HANDLE hHeap);

namespace ATL {
__interface __declspec(uuid("654F7EF5-CFDF-4df9-A450-6C6A13C622C0")) IAtlMemMgr
{
public:
    void* Allocate(size_t nBytes);
    void Free(void* p);
    void* Reallocate(void* p, size_t nBytes);
    size_t GetSize(void* p);
};

class CWin32Heap : public IAtlMemMgr
{
public:
    CWin32Heap(HANDLE hHeap) throw() :
        m_hHeap(hHeap),
        m_bOwnHeap(false)
    {
    }
    ~CWin32Heap() throw()
    {
        if (m_bOwnHeap && (m_hHeap != NULL))
            ::HeapDestroy(m_hHeap);
    }

    virtual void* Allocate(size_t nBytes) throw();
    virtual void Free(void* p) throw();
    virtual void* Reallocate(void* p, size_t nBytes) throw();
    virtual size_t GetSize(void* p) throw();

public:
    HANDLE m_hHeap;
    bool m_bOwnHeap;
};
}

static ATL::CWin32Heap processHeap(::GetProcessHeap());
