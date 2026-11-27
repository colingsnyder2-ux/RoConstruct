// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)
struct counted {
    virtual ~counted();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use; long weak;
    void release() {
        if (_InterlockedDecrement(&use) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak) == 0) destroy();
        }
    }
};
struct SC {
    counted* pi;
    SC(const SC& r) : pi(r.pi) { if (pi) _InterlockedIncrement(&pi->use); }
    ~SC() { if (pi) pi->release(); }
};
struct T;
struct SP {
    T* px; SC pn;
    SP(int, int, T* p, SC c);
};
SP::SP(int, int, T* p, SC c) : px(p), pn(c) {}
