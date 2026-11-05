// from server: 100% by EspClaude
// from server: 91% by king_originala_sol_resume_root
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_72d0f35278ad032c.cpp

// Candidate translation unit (score above; library headers required).
#include <algorithm>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>


extern "C" __declspec(dllimport) int __stdcall ReleaseCapture();
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

struct Object;
typedef boost::shared_ptr<Object> Shared;

struct Event {
    virtual void invoke(int);
};

struct Object {
    char padding[0x1f0];
    Event event;
};

struct DragSelection {
    virtual void* GetRuntimeClass() const;
    virtual ~DragSelection();
};

struct CDllIsolationWrapperBase { virtual ~CDllIsolationWrapperBase(); };
struct CComCtlWrapper : CDllIsolationWrapperBase {
    int _ImageList_DragLeave(void* hwndLock);
    void _ImageList_EndDrag();
};

struct ModuleState {
    char padding[0x94];
    CDllIsolationWrapperBase** m_pDllIsolationWrappers;
};

ModuleState* __stdcall AfxGetModuleState();
#define afxComCtlWrapper static_cast<CComCtlWrapper*>(AfxGetModuleState()->m_pDllIsolationWrappers[0])
inline void __stdcall AfxImageList_EndDrag() { afxComCtlWrapper->_ImageList_EndDrag(); }
inline int __stdcall AfxImageList_DragLeave(void* hwndLock) { return afxComCtlWrapper->_ImageList_DragLeave(hwndLock); }

struct Item {
    char padding[12];
    Shared value;
};

struct Selection {
 typedef std::vector<Shared>::const_iterator const_iterator;
 const_iterator begin() const;
 const_iterator end() const;
};
typedef char iterator_size_check[sizeof(Selection::const_iterator)==8?1:-1];
typedef char shared_size_check[sizeof(Shared)==8?1:-1];

template<class T> inline void SafeDelete(T*& p) { delete p; p = 0; }
struct Guard {
    unsigned int storage[3];
    Guard(Shared);
    ~Guard();
};

void __cdecl callback(Object*, Shared);

void __cdecl notify(const char*, Object*);
extern const char drop[];

#define V(N) virtual void slot##N();
#define V10(N) V(N##0) V(N##1) V(N##2) V(N##3) V(N##4) \
               V(N##5) V(N##6) V(N##7) V(N##8) V(N##9)

struct S {
    V10(0)
    V10(1)
    V10(2)
    V10(3)
    V10(4)
    V10(5)
    V10(6)
    V10(7)
    V(80) V(81) V(82) V(83)
    virtual Selection* range();

    char padding0[0x1c];
    void* window;
    char padding1[0x100];
    Shared owner;
    DragSelection* selection;

    void prepare();
    unsigned long GetItemData(long) const;
    void* GetSafeHwnd() const { return this == 0 ? 0 : window; }
    long GetDropHilightItem() const { return SendMessageA(window, 0x110a, 8, 0); }
    int SelectDropTarget(long h) { return (int)SendMessageA(window, 0x110b, 8, h); }
    static int DragLeave(S* pWndLock) { return AfxImageList_DragLeave(pWndLock->GetSafeHwnd()); }
    static void EndDrag() { AfxImageList_EndDrag(); }
    void finish(unsigned int, unsigned int, long);
};

#undef V10
#undef V

void S::finish(unsigned int, unsigned int, long) {
    prepare();
    DragSelection* dragging = selection;
    if (dragging) {
        DragLeave(this);
        EndDrag();
        ReleaseCapture();
        SafeDelete(selection);

        long handle = GetDropHilightItem();
        if (handle) {
            Item* selected = (Item*)GetItemData(handle);
            if (selected) {
                Shared value(selected->value);
                Object* object = value.get();
                Guard guard(owner);

                if (object) {
                    std::for_each(range()->begin(), range()->end(), boost::bind(callback, object, _1));
                }

                notify(drop, owner.get());
                owner.get()->event.invoke(1);
            }
        }

        SelectDropTarget(0);
    }
}
