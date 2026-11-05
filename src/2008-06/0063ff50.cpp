// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
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
struct static_cast_tag {};
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
    shared_ptr& operator=(const shared_ptr& r){px=r.px;pn=r.pn;return *this;}
    void swap(shared_ptr& r){std::swap(px,r.px);pn.swap(r.pn);}
    void reset(){shared_ptr().swap(*this);}
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type()const{return px==0?0:&shared_ptr::px;}
    shared_ptr(const shared_ptr& r):px(r.px),pn(r.pn){}
    template<class Y> shared_ptr(const shared_ptr<Y>& r):px(r.px),pn(r.pn){}
    template<class Y> __declspec(noinline) shared_ptr(const shared_ptr<Y>&r,detail::static_cast_tag):px(static_cast<T*>(r.px)),pn(r.pn){}
    T* get()const{return px;}
    T* operator->()const{return px;}
};
template<class T,class U> __declspec(noinline) shared_ptr<T> static_pointer_cast(const shared_ptr<U>&r){return shared_ptr<T>(r,detail::static_cast_tag());}
template<class T,class U> bool operator==(const shared_ptr<T>& a,const shared_ptr<U>& b){return a.get()==b.get();}
}

namespace G3D {struct Vector3 {float x,y,z;};struct CoordinateFrame {float rotation[9];Vector3 translation;};}
namespace RBX {
class Instance {public:boost::shared_ptr<Instance> clone();};
class PartInstance:public Instance {public:const G3D::CoordinateFrame& getCoordinateFrame()const;};

struct UIEvent;
struct Workspace:Instance {void insertInstances(const std::vector<boost::shared_ptr<Instance> >&,Instance*,int,int);};
struct ServiceProvider {void postInsert(int);};
ServiceProvider* __cdecl findServiceProvider(Instance*);
struct MouseCommand {virtual void slot0();virtual MouseCommand* onMouseDown(const UIEvent&);char prefix[0x18-4];Workspace* workspace;};
struct DragCommand:MouseCommand {char tail[0x44-0x1c];DragCommand(PartInstance*,const G3D::Vector3&,Workspace*,boost::shared_ptr<Instance>);};
struct CloneTool:MouseCommand {PartInstance* mousePart;MouseCommand* onMouseDown(const UIEvent&);};
MouseCommand* CloneTool::onMouseDown(const UIEvent& event){
 if(mousePart){
  mousePart->getCoordinateFrame();
  boost::shared_ptr<PartInstance> part=boost::static_pointer_cast<PartInstance>(mousePart->clone());
  std::vector<boost::shared_ptr<Instance> > instances;
  instances.push_back(part);
  workspace->insertInstances(instances,workspace,1,1);
  findServiceProvider(workspace)->postInsert(8);
  MouseCommand* command=new DragCommand(part.get(),part->getCoordinateFrame().translation,workspace,boost::shared_ptr<Instance>());
  return command->onMouseDown(event);
 }
 return 0;
}
}
