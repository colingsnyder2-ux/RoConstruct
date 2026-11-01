// from server: 95% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <intrin.h>
namespace boost {
namespace detail {
inline long atomic_decrement(long* pw) { return _InterlockedDecrement(pw); }
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void weak_release() { if (atomic_decrement(&weak_count_) == 0) destroy(); }
    void release() { if (atomic_decrement(&use_count_) == 0) { dispose(); weak_release(); } }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public: shared_ptr(const shared_ptr&); T* get() const { return px; }
public:
    T* px;
    detail::shared_count pn;
};
}
namespace boost {
template<class T> class weak_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr<T> lock() const;
};
}
namespace RBX {
class PartInstance { public: static bool nonNullInWorkspace(boost::shared_ptr<PartInstance> part); };
class ICameraOwner { public: void setCameraIgnoreParts(PartInstance* part); };
class Workspace { public: char pad[0x118]; ICameraOwner cameraOwner; };
class DragUtilities { public: static void unJoinAndSetDragging(std::vector<boost::weak_ptr<PartInstance> >& parts); };
class MegaDragger {
public:
    boost::weak_ptr<PartInstance> mousePart;
    std::vector<boost::weak_ptr<PartInstance> > dragParts;
    bool joined;
    int extra;
    Workspace* rootInstance;
    void* contactManager;
    void startDragging();
};
void MegaDragger::startDragging()
{
    DragUtilities::unJoinAndSetDragging(dragParts);
    if (PartInstance::nonNullInWorkspace(mousePart.lock()))
    {
        boost::shared_ptr<PartInstance> p = mousePart.lock();
        rootInstance->cameraOwner.setCameraIgnoreParts(p.get());
    }
    joined = false;
}
}
