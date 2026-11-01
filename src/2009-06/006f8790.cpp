// from server: 93% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_c43eb16e9a53bcfd.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include "G3D/CoordinateFrame.h"
#include "util/Velocity.h"
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_add_ref() { _InterlockedIncrement(&weak_count_); }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
class weak_count {
public:
    sp_counted_base* pi_;
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
    weak_count& operator=(weak_count const& r) {
        sp_counted_base* tmp = r.pi_;
        if (tmp != pi_) {
            if (tmp != 0) tmp->weak_add_ref();
            if (pi_ != 0) pi_->weak_release();
            pi_ = tmp;
        }
        return *this;
    }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    ~shared_ptr() { if (pn != 0) pn->release(); }
    T* operator->() const { return px; }
    T* get() const { return px; }
};
template<class T> class weak_ptr {
public:
    T* px;
    detail::weak_count pn;
    shared_ptr<T> lock() const;
};
}
struct Primitive {const G3D::CoordinateFrame&getFrame();void setVelocity(const RBX::Velocity&);};
struct Part{char pad[0x118];Primitive* primitive;Primitive* getPrimitive() const {return primitive;}};
struct Workspace;
struct SnapInfo{Primitive*snap;int surface;G3D::Vector3 hitWorld,lastDragSnap;SnapInfo():surface(6),hitWorld(G3D::Vector3::inf()),lastDragSnap(G3D::Vector3::inf()),snap(0){}};
extern void turnUpright(Part*);
struct Dragger{boost::weak_ptr<Part>dragPart,snapPart;Workspace*workspace;Primitive*drag;G3D::Vector3 dragPointLocal;SnapInfo snapInfo;void init(Workspace*,boost::weak_ptr<Part>,const G3D::Vector3&);};
void Dragger::init(Workspace*w,boost::weak_ptr<Part>part,const G3D::Vector3&hit){
 workspace=w;dragPart=part;
 boost::shared_ptr<Part> p=dragPart.lock();
 Part* pp=p.get();

 drag=pp->primitive;
 dragPointLocal=hit;
 drag->setVelocity(RBX::Velocity::zero());
 snapInfo=SnapInfo();
 turnUpright(pp);
}
