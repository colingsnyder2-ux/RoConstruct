// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
#include <intrin.h>
struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0)
                destroy();
        }
    }
};
template<class T> struct shared_ptr {
    T* px;
    sp_counted_base* pi;
    ~shared_ptr() { if (pi) pi->release(); }
    T* operator->() const { return px; }
};
struct VerbContainer { virtual ~VerbContainer(); };
struct Workspace { char pad[0x158]; VerbContainer vc; };
struct DataModel { char pad[0x20c]; Workspace* workspace; };
class Owner {
public:
    shared_ptr<DataModel> getDataModel();
    VerbContainer* getVerbContainer();
};
inline VerbContainer* toVC(Workspace* w) { return w ? &w->vc : 0; }
VerbContainer* Owner::getVerbContainer()
{
    return toVC(getDataModel()->workspace);
}
