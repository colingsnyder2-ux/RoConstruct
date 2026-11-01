// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose()=0;
    virtual void destroy(){delete this;}
    long use_count_,weak_count_;
    void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
    void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
struct shared_count {
    sp_counted_base* pi_;
    ~shared_count(){if(pi_)pi_->release();}
};
struct weak_count {
    sp_counted_base* pi_;
    ~weak_count(){if(pi_)pi_->weak_release();}
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    T* get()const{return px;}
    T* operator->()const{return px;}
};
template<class T> class weak_ptr {
public:
    T* px; detail::weak_count pn;
    shared_ptr<T> lock() const;
    template<class Y> weak_ptr& operator=(const shared_ptr<Y>& r);
};
}
namespace RBX {
class Primitive;
class PartInstance {
public:
    char pad[0x118];
    Primitive* primitive;
    Primitive* getPrimitive() const { return primitive; }
};
template<class T> boost::shared_ptr<T> shared_from(T* p);
class Joint {
public:
    virtual ~Joint();
    virtual void v1();
    virtual void v2();
    virtual void setPrimitive(int i, Primitive* p);
};
class AutoJoint {
public:
    char pad[0x9c];
    boost::weak_ptr<PartInstance> part[2];
    Joint* joint;
    void setPart(int index, PartInstance* value);
};
void AutoJoint::setPart(int index, PartInstance* value)
{
    boost::shared_ptr<PartInstance> current = part[index].lock();
    if (current.get() != value) {
        part[index] = shared_from(value);
        joint->setPrimitive(index, value ? value->getPrimitive() : 0);
    }
}
}
