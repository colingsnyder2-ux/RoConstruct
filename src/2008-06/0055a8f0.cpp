// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// Native openrbx GuidItem/Instance virtual hierarchy and target RTTI establish these ABI views.
// Native Events, CopyOnWrite, Boost and STL operations preserve notification/ownership lifetimes.
// Unused native APIs are omitted; all accessed member offsets are compile-asserted.
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <intrin.h>
#include <utility>
#include <stddef.h>
#include <ostream>
namespace boost {
namespace detail {
struct sp_counted_base {
    sp_counted_base():use_count_(1),weak_count_(1){}
    virtual ~sp_counted_base() {}
    virtual void dispose()=0;
    virtual void destroy(){delete this;}
    long use_count_,weak_count_;
    void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
    void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
template<class Y>struct sp_counted_impl_p:sp_counted_base {Y*pointer;explicit sp_counted_impl_p(Y*p):pointer(p){}void dispose(){delete pointer;}};
struct shared_count {
    sp_counted_base* pi_;
    shared_count():pi_(0){}
    
    shared_count& operator=(const shared_count& r){sp_counted_base* tmp=r.pi_;if(tmp!=pi_){if(tmp)_InterlockedIncrement(&tmp->use_count_);if(pi_)pi_->release();pi_=tmp;}return *this;}
    void swap(shared_count& r){sp_counted_base* tmp=r.pi_;r.pi_=pi_;pi_=tmp;}
    shared_count(const shared_count& r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}
    ~shared_count(){if(pi_)pi_->release();}
};
}
namespace detail {inline void sp_enable_shared_from_this(const shared_count&,...) {}}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr():px(0),pn(){}
    
    shared_ptr& operator=(const shared_ptr& r){px=r.px;pn=r.pn;return *this;}
    void swap(shared_ptr& r){std::swap(px,r.px);pn.swap(r.pn);}
    void reset(){shared_ptr().swap(*this);}
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type()const{return px==0?0:&shared_ptr::px;}
    __declspec(noinline) shared_ptr(const shared_ptr& r):px(r.px),pn(r.pn){}
    template<class Y> __declspec(noinline) shared_ptr(const shared_ptr<Y>& r):px(r.px),pn(r.pn){}
    T* get()const{return px;}
    T* operator->()const{return px;}
};
template<class T,class U> bool operator==(const shared_ptr<T>& a,const shared_ptr<U>& b){return a.get()==b.get();}
}




namespace boost {
struct noncopyable{};
template<class T>struct weak_ptr {T*px;void*count;};
template<class T>struct enable_shared_from_this {weak_ptr<T>weak_this;shared_ptr<T>shared_from_this();};
}
namespace G3D {std::string __cdecl format(const char*,...);}
namespace RBX {
struct Name;struct Instance;struct XmlElement;struct IReferenceBinder;struct ServiceProvider;
struct Guid:boost::noncopyable {const Name*scope;int index;};
template<class T>struct GuidItem {virtual ~GuidItem();bool registeredGuid;Guid guid;};
struct Object {virtual ~Object();};template<class T>struct Creatable:Object{};
template<class T>struct AbstractFactoryProduct:Creatable<T> {virtual const Name&getClassName()const=0;};
namespace Reflection {
struct PropertyDescriptor;struct SignalSource {virtual ~SignalSource();void*signals;};
struct DescribedBase:SignalSource {void*descriptor;};
struct ChildSignal {void fire(SignalSource*,boost::shared_ptr<Instance>)const;};
}
struct Debugable {virtual void dump(std::ostream&);};
struct RaiseRange;
template<class T,class Event>struct Listener;
template<class T,class Event>struct Notifier {
 virtual ~Notifier();std::vector<Listener<T,Event>*>listeners;RaiseRange*range;
 virtual void onAddListener(Listener<T,Event>*)const;virtual void onRemoveListener(Listener<T,Event>*)const;
 __declspec(nothrow) void raise(Event)const;
};
template<class T>boost::shared_ptr<T> __cdecl shared_from(T*);
struct ChildAdded {const boost::shared_ptr<Instance>child;ChildAdded(Instance*p):child(shared_from(p)){}};
struct ChildRemoved {const boost::shared_ptr<Instance>child;ChildRemoved(Instance*p):child(shared_from(p)){}};
struct DescendentAdded;struct DescendentRemoving;struct PropertyChanged;
struct AncestorChanged {Instance*const child;Instance*const oldParent;Instance*const newParent;AncestorChanged(Instance*c,Instance*o,Instance*n):child(c),oldParent(o),newParent(n){}};
template<class T>struct Association {struct Item;std::vector<Item*>items;};
template<class T>struct CopyOnWrite:boost::noncopyable {
 boost::shared_ptr<T>object;
 operator typename boost::shared_ptr<T>::unspecified_bool_type()const{return object;}
 const T*operator->()const{return object.get();}boost::shared_ptr<T>&write();void reset();
};
struct Instance:GuidItem<Instance>,AbstractFactoryProduct<Instance>,Reflection::DescribedBase,Debugable,
 Notifier<Instance,ChildAdded>,Notifier<Instance,ChildRemoved>,Notifier<Instance,DescendentAdded>,Notifier<Instance,DescendentRemoving>,Notifier<Instance,AncestorChanged>,Notifier<Instance,PropertyChanged>,boost::enable_shared_from_this<Instance>,boost::noncopyable {
 virtual ~Instance();virtual void setName(const std::string&);
 virtual bool askAddChild(const Instance*)const;virtual bool askSetParent(const Instance*)const;
 virtual void onAncestorChanged(const AncestorChanged&);virtual void onDescendentAdded(Instance*);virtual void onDescendentRemoving(const boost::shared_ptr<Instance>&);
 virtual void onChildAdded(Instance*);virtual void onChildRemoving(Instance*);virtual void onChildRemoved(Instance*);virtual void onLastChildRemoved();
 virtual void readProperty(const XmlElement*,IReferenceBinder&);virtual void onServiceProvider(const ServiceProvider*,const ServiceProvider*);virtual boost::shared_ptr<Instance>createChild(const Name&);virtual XmlElement*write();virtual void onChildChanged(Instance*,const PropertyChanged&);
 Association<Instance>assoc;Instance*parent;CopyOnWrite<std::vector<boost::shared_ptr<Instance> > >children;std::string name;bool archivable;
 static Reflection::ChildSignal event_childAdded,event_childRemoved;static const Reflection::PropertyDescriptor propParent;
 std::string getFullName()const;bool isAncestorOf(const Instance*)const;bool contains(const Instance*child)const;
 unsigned numChildren()const{return children?children->size():0;}
 static void signalDescendentRemoving(const boost::shared_ptr<Instance>&,Instance*,Instance*);static void signalDescendentAdded(Instance*,Instance*,Instance*);
 void raisePropertyChanged(const Reflection::PropertyDescriptor&);void setParent(Instance*);
};
bool Instance::contains(const Instance*child)const{while(child){if(child==this)return true;child=child->parent;}return false;}
void Instance::setParent(Instance*newParent){
 Instance*previousParent=parent;
 if(newParent==previousParent)return;
 if(this==newParent){std::string message=G3D::format("Attempt to set %s as its own parent",getFullName().c_str());throw std::runtime_error(message);}
 if(isAncestorOf(newParent)){std::string message=G3D::format("Attempt to set parent of %s to %s results in circular reference",getFullName().c_str(),newParent->getFullName().c_str());throw std::runtime_error(message);}
 boost::shared_ptr<Instance>oldParent=shared_from(previousParent);
 boost::shared_ptr<Instance>self=shared_from_this();
 if(oldParent){
  if(!oldParent->contains(newParent))signalDescendentRemoving(self,oldParent.get(),newParent);
  oldParent->onChildRemoving(this);
  boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > >&c=oldParent->children.write();
  c->erase(std::find(c->begin(),c->end(),self));
  if(c->size()==0)oldParent->children.reset();
  parent=0;
  event_childRemoved.fire(oldParent.get(),self);
  oldParent->Notifier<Instance,ChildRemoved>::raise(ChildRemoved(this));
  oldParent->onChildRemoved(this);
  if(oldParent->numChildren()==0)oldParent->onLastChildRemoved();
 }
 if(newParent)newParent->children.write()->push_back(self);
 parent=newParent;
 if(newParent){
  newParent->onChildAdded(this);
  if(!newParent->contains(oldParent.get()))signalDescendentAdded(this,newParent,oldParent.get());
  newParent->Notifier<Instance,ChildAdded>::raise(ChildAdded(this));
  event_childAdded.fire(newParent,self);
 }
 onAncestorChanged(AncestorChanged(this,oldParent.get(),newParent));raisePropertyChanged(propParent);
}
}
typedef char guid_item_size[sizeof(RBX::GuidItem<RBX::Instance>)==16?1:-1];
typedef char notifier_size[sizeof(RBX::Notifier<RBX::Instance,RBX::ChildAdded>)==32?1:-1];
typedef char association_offset[offsetof(RBX::Instance,assoc)==0xec?1:-1];
typedef char parent_offset[offsetof(RBX::Instance,parent)==0x104?1:-1];
typedef char children_offset[offsetof(RBX::Instance,children)==0x108?1:-1];
typedef char name_offset[offsetof(RBX::Instance,name)==0x110?1:-1];


