// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
#include <utility>
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
    shared_count():pi_(0){}
    shared_count& operator=(const shared_count& r){sp_counted_base* tmp=r.pi_;if(tmp!=pi_){if(tmp)_InterlockedIncrement(&tmp->use_count_);if(pi_)pi_->release();pi_=tmp;}return *this;}
    void swap(shared_count& r){sp_counted_base* tmp=r.pi_;r.pi_=pi_;pi_=tmp;}
    shared_count(const shared_count& r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}
    ~shared_count(){if(pi_)pi_->release();}
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr():px(0),pn(){}
    __declspec(noinline) shared_ptr& operator=(const shared_ptr& r){px=r.px;pn=r.pn;return *this;}
    void swap(shared_ptr& r){std::swap(px,r.px);pn.swap(r.pn);}
    void reset(){shared_ptr().swap(*this);}
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type()const{return px==0?0:&shared_ptr::px;}
    shared_ptr(const shared_ptr& r):px(r.px),pn(r.pn){}
    template<class Y> shared_ptr(const shared_ptr<Y>& r):px(r.px),pn(r.pn){}
    T* get()const{return px;}
    T* operator->()const{return px;}
};
template<class T,class U> bool operator==(const shared_ptr<T>& a,const shared_ptr<U>& b){return a.get()==b.get();}
}

namespace RBX {
namespace Reflection {struct DescribedBase {virtual void slot0();};}
struct Primary {virtual void slot0();char prefix[16];};
class Instance:public Primary,public Reflection::DescribedBase {};
boost::shared_ptr<Instance> __cdecl shared_from(Instance*);
namespace Reflection {
struct Type {static const Type& sharedType();};
struct Variant {const Type* type;boost::shared_ptr<DescribedBase> value;Variant& operator=(const boost::shared_ptr<DescribedBase>&v){type=&Type::sharedType();value=v;return *this;}};
struct GetSet {virtual void slot0();virtual bool isReadOnly()const;virtual Instance* getValue(const DescribedBase*)const;};
struct RefPropDescriptor {char prefix[0x1c];GetSet* getset;void getVariant(const DescribedBase*,Variant&)const;};
void RefPropDescriptor::getVariant(const DescribedBase* instance,Variant& value)const{
 boost::shared_ptr<DescribedBase> reference=shared_from(getset->getValue(instance));
 value=reference;
}
}}
