// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
namespace RBX {
class Instance;
struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strongCount;
    volatile long weakCount;
    void release() {
        if (_InterlockedDecrement(&strongCount) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weakCount) == 0)
            destroy();
    }
};
struct SharedInstance {
    Instance* ptr;
    Control* control;
    Instance* get() const { return ptr; }
    ~SharedInstance() {
        if (control != 0) control->release();
    }
};
struct WeakInstance {
    Instance* ptr;
    Control* control;
    SharedInstance lock() const;
    WeakInstance& operator=(const SharedInstance& r);
};
SharedInstance shared_from(Instance* p);
extern char desc_Value[];
class Holder {
public:
    char pad[0x8c];
    WeakInstance value;
    void raisePropertyChanged(const void* desc);
    void setValue(Instance* v);
};
void Holder::setValue(Instance* v)
{
    SharedInstance cur = value.lock();
    if (cur.get() != v) {
        value = shared_from(v);
        raisePropertyChanged(desc_Value);
    }
}
}
