// from server: 80% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <exception>
#include <vector>
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement)
extern "C" __declspec(dllimport) int __stdcall ReleaseCapture();
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

struct Counted { virtual ~Counted(); long use_count_; long weak_count_; };
template<class T> struct Shared {
    T* px; Counted* pn;
    Shared(const Shared& r) : px(r.px), pn(r.pn) { if (pn) _InterlockedIncrement(&pn->use_count_); }
    ~Shared();
    T* get() const { return px; }
};
struct Event { virtual void invoke(int); };
struct Object { char padding[0xf8]; Event event; };
typedef Shared<Object> SharedObject;

struct DragSelection { virtual void* GetRuntimeClass() const; virtual ~DragSelection(); };
struct CDllIsolationWrapperBase { virtual ~CDllIsolationWrapperBase(); };
struct CComCtlWrapper : CDllIsolationWrapperBase {
    int _ImageList_DragLeave(void* hwndLock);
    void _ImageList_EndDrag();
};
struct ModuleState { char padding[0x94]; CDllIsolationWrapperBase** m_pDllIsolationWrappers; };
ModuleState* __stdcall AfxGetModuleState();
#define afxComCtlWrapper static_cast<CComCtlWrapper*>(AfxGetModuleState()->m_pDllIsolationWrappers[0])
inline void __stdcall AfxImageList_EndDrag() { afxComCtlWrapper->_ImageList_EndDrag(); }
inline int __stdcall AfxImageList_DragLeave(void* hwndLock) { return afxComCtlWrapper->_ImageList_DragLeave(hwndLock); }

struct Item { char padding[0x14]; SharedObject value; };
typedef std::vector<SharedObject>::const_iterator Iter;
struct Selection { Iter begin() const; Iter end() const; };
template<class T> inline void SafeDelete(T*& p) { delete p; p = 0; }
struct Guard { void* p; Guard(SharedObject, bool); ~Guard(); };
struct Bound { void (*f)(Object*, SharedObject); Object* o; Bound(void (*f_)(Object*, SharedObject), Object* o_) : f(f_), o(o_) {} };
inline Bound bindCallback(void (*f)(Object*, SharedObject), Object* o) { return Bound(f, o); }
void __cdecl callback(Object*, SharedObject);
Bound __cdecl for_each(Iter first, Iter last, Bound f);
void __cdecl notify(const char*, Object*);
void __cdecl reportException(std::exception& e);
int __cdecl messageBox(const char*, unsigned int, unsigned int);

#define V(N) virtual void slot##N();
#define V10(N) V(N##0) V(N##1) V(N##2) V(N##3) V(N##4) V(N##5) V(N##6) V(N##7) V(N##8) V(N##9)
struct S {
    V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7)
    V(80) V(81) V(82) V(83)
    virtual Selection* range();
    char padding0[0x1c];
    void* window;
    char padding1[0x108];
    SharedObject owner;
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
void S::finish(unsigned int, unsigned int, long) {
    try {
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
                    SharedObject value(selected->value);
                    Object* object = value.get();
                    Guard guard(owner, true);
                    if (object) {
                        for_each(range()->begin(), range()->end(), bindCallback(callback, object));
                    }
                    notify("Drop", owner.get());
                    owner.get()->event.invoke(1);
                }
            }
            SelectDropTarget(0);
        }
    } catch (std::exception& e) {
        reportException(e);
        messageBox(e.what(), 0x10, 0);
    }
}
