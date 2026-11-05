// from server: 100% by EspClaude
// from server: 88% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
    ~shared_ptr(){}
    shared_ptr& operator=(const shared_ptr& r){px=r.px;pn=r.pn;return *this;}
    void swap(shared_ptr& r){std::swap(px,r.px);pn.swap(r.pn);}
    __forceinline void reset(){shared_ptr().swap(*this);}
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
class Instance {public:virtual ~Instance();char prefix[0x100];Instance*parent;Instance*getParent()const{return parent;}};
class PartInstance:public Instance {};
class Texture:public Instance {};
class Decal:public Instance {};
boost::shared_ptr<PartInstance> __cdecl shared_from(PartInstance*);
template<class T> inline T* w0(T* p){return p;}
template<class T> inline T* w1(T* p){return w0(p);}
template<class T> inline T* w2(T* p){return w1(p);}
template<class T> inline T* w3(T* p){return w2(p);}
template<class T> inline T* w4(T* p){return w3(p);}
template<class T> inline T* w5(T* p){return w4(p);}
template<class T> inline T* w6(T* p){return w5(p);}
template<class T> inline T* w7(T* p){return w6(p);}
template<class T> inline T* w8(T* p){return w7(p);}
template<class T> inline T* w9(T* p){return w8(p);}
template<class T> inline T* w10(T* p){return w9(p);}
template<class T> inline T* w11(T* p){return w10(p);}
template<class T> inline T* w12(T* p){return w11(p);}
template<class T> inline T* w13(T* p){return w12(p);}
template<class T> inline T* w14(T* p){return w13(p);}
template<class T> inline T* w15(T* p){return w14(p);}
template<class T> inline T* w16(T* p){return w15(p);}
template<class T> inline T* w17(T* p){return w16(p);}
template<class T> inline T* w18(T* p){return w17(p);}
template<class T> inline T* w19(T* p){return w18(p);}
template<class T> inline T* w20(T* p){return w19(p);}
template<class T> inline T* w21(T* p){return w20(p);}
template<class T> inline T* w22(T* p){return w21(p);}
template<class T> inline T* w23(T* p){return w22(p);}
template<class T> inline T* w24(T* p){return w23(p);}
template<class T> inline T* w25(T* p){return w24(p);}
template<class T> inline T* w26(T* p){return w25(p);}
template<class T> inline T* w27(T* p){return w26(p);}
template<class T> inline T* w28(T* p){return w27(p);}
template<class T> inline T* w29(T* p){return w28(p);}
template<class T> inline T* w30(T* p){return w29(p);}
template<class T> inline T* w31(T* p){return w30(p);}
template<class T> inline T* w32(T* p){return w31(p);}
template<class T> inline T* w33(T* p){return w32(p);}
template<class T> inline T* w34(T* p){return w33(p);}
template<class T> inline T* w35(T* p){return w34(p);}
template<class T> inline T* w36(T* p){return w35(p);}
template<class T> inline T* w37(T* p){return w36(p);}
template<class T> inline T* w38(T* p){return w37(p);}
template<class T> inline T* w39(T* p){return w38(p);}
template<class T> inline T* fastDynamicCast(Instance* i){return w39(w39(dynamic_cast<T*>(w39(w39(i)))));}
namespace ViewNew {
class ViewRbxGfx;
class Part {char storage[0xf0];public:Part(const boost::shared_ptr<PartInstance>&,ViewRbxGfx*);};
class Texture {char storage[0x108];public:Texture(RBX::Texture&,PartInstance&,ViewRbxGfx*);};
class Decal {char storage[0x108];public:Decal(RBX::Decal&,PartInstance&,ViewRbxGfx*);};
class ViewRbxGfx {public:void onWorkspaceDescendentAdded(boost::shared_ptr<Instance>);};
void ViewRbxGfx::onWorkspaceDescendentAdded(boost::shared_ptr<Instance>instance){
 if(PartInstance*part=fastDynamicCast<PartInstance>(instance.get())){
  new Part(shared_from(part),this);
  return;
 }
 {
  PartInstance*parent=fastDynamicCast<PartInstance>(instance->getParent());
  RBX::Texture*texture;
  if(parent && (texture=fastDynamicCast<RBX::Texture>(instance.get()))){
   new Texture(*texture,*parent,this);
  }else if(RBX::Decal*decal=fastDynamicCast<RBX::Decal>(instance.get())){
   new Decal(*decal,*dynamic_cast<PartInstance*>(decal->getParent()),this);
  }
 }
}
}}
