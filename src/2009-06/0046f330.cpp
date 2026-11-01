// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_d9b2961fb6bcb379.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <new>
#include <afxwin.h>
#include <fstream>
#include <memory>
#include <intrin.h>

struct sp_counted_base { void* vtbl; long use_count_; long weak_count_; };
template<class T> struct shared_ptr {
    T* px; sp_counted_base* pn;
    shared_ptr(const shared_ptr& r) : px(r.px), pn(r.pn) { if (pn) _InterlockedIncrement(&pn->use_count_); }
    ~shared_ptr();
};
struct DataModel;
struct PathString {
    char* m_pszData;
    __declspec(dllimport) PathString(const wchar_t* psz);
    __declspec(dllimport) operator const char*() const throw();
    __declspec(dllimport) ~PathString() throw();
};
template<class T> inline void checked_delete(T* x) { typedef char type_must_be_complete[sizeof(T) ? 1 : -1]; (void)sizeof(type_must_be_complete); delete x; }
template<class T> struct WPtr { T* p; ~WPtr() { checked_delete(p); } T* get() const { return p; } };
struct Lock { Lock(shared_ptr<DataModel> dm, bool b = true); ~Lock(); int a; };
struct WriterPool { CRITICAL_SECTION cs; void* head; static WriterPool* get(); };
extern long writerCount;
struct Writer { ~Writer(); int x;
    static void operator delete(void* p) {
        WriterPool* pool = WriterPool::get();
        EnterCriticalSection(&pool->cs);
        *(void**)p = pool->head;
        pool->head = p;
        LeaveCriticalSection(&pool->cs);
        InterlockedDecrement(&writerCount);
    }
};

class VCWorkspace {
public:
    char pad[0x1c];
    shared_ptr<DataModel> dm;
    WPtr<Writer> createWriter();
    void write(Writer* w, std::ostream& s);
    HRESULT __stdcall Save(BSTR path) throw();
};

HRESULT __stdcall VCWorkspace::Save(BSTR path) throw()
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    std::ofstream stream;
    stream.open(PathString(path), std::ios::out | std::ios::binary);
    Lock lock(dm);
    write(createWriter().get(), stream);
    return S_OK;
}

