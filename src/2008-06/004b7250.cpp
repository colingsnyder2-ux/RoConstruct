// from server: 100% by EspClaude
// roc 2008-06 004b7250  unit: RBX::Network::Replicator::ChangePropertyItem  size: 2006 bytes
// Replicator::readInstanceNew. Class dictionary receive inlined (unsigned id=0; ReadBits(&id,bits); items[id]);
// Settings::printInstances read as a real member (field<> accessor perturbed register coalescing).
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lang: cpp
// Complete native readInstanceNew, including the cold parent-property branch.
// Native MSVCP90 checked STL and exact adjacent subscription/Instance code establish this profile.
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <intrin.h>
#include <utility>
#include <stddef.h>
#include <ostream>
namespace RakNet {class BitStream {public:bool ReadBits(unsigned char*,int,bool);};}
namespace boost {
namespace detail {
class sp_counted_base {public:
    sp_counted_base():use_count_(1),weak_count_(1){}
    virtual ~sp_counted_base() {}
    virtual void dispose()=0;
    virtual void destroy(){delete this;}
    long use_count_,weak_count_;
    void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
    void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
template<class Y>struct sp_counted_impl_p:sp_counted_base {Y*pointer;explicit sp_counted_impl_p(Y*p):pointer(p){}void dispose(){delete pointer;}};
class shared_count {public:
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
    shared_ptr(const shared_ptr& r):px(r.px),pn(r.pn){}
    template<class Y> shared_ptr(const shared_ptr<Y>& r):px(r.px),pn(r.pn){}
    T* get()const{return px;}
    T* operator->()const{return px;}
};
template<class T,class U> bool operator==(const shared_ptr<T>& a,const shared_ptr<U>& b){return a.get()==b.get();}
}


namespace boost {
namespace detail {template<class T>struct empty_base{};}
template<class T,class B=detail::empty_base<T> >struct less_than_comparable1:B{};
template<class T,class B=detail::empty_base<T> >struct equality_comparable1:B{};
namespace signals {
struct basic_connection {void*signal;void*signal_data;void(*signal_disconnect)(void*,void*);};
class connection:private less_than_comparable1<connection>,private equality_comparable1<connection> {public:
 shared_ptr<basic_connection>con;bool controlling_connection;
 connection():con(),controlling_connection(false){}connection(const connection&);~connection();connection&operator=(const connection&);void disconnect()const;
 bool connected()const{return con.get()&&con->signal_disconnect;}
};
}
}
namespace boost {
struct noncopyable{};
template<class T>struct weak_ptr {T*px;void*count;};
template<class T>struct enable_shared_from_this {weak_ptr<T>weak_this;shared_ptr<T>shared_from_this();};
}
namespace G3D {std::string __cdecl format(const char*,...);}
namespace RBX {
class Name;class Instance;struct XmlElement;struct IReferenceBinder;struct ServiceProvider;
class Guid:public boost::noncopyable {public:struct Data {const Name*scope;int index;std::string readableString(int)const;};Data data;void assign(Data);};
class Name {int dictionaryIndex;public:const std::string name;const char*c_str()const{return name.c_str();}};
template<class T>struct GuidItem {virtual void onGuidChanged();bool registeredGuid;Guid guid;void registerGuid();void unregisterGuid();static __declspec(noalias) bool find(const Guid::Data&,Instance*&);};
struct Object {virtual ~Object();};template<class T>struct Creatable:Object{};
template<class T>struct AbstractFactoryProduct:Creatable<T> {virtual const Name&getClassName()const=0;};
namespace Reflection {
class ClassDescriptor {public:virtual~ClassDescriptor();const Name*name;bool operator!=(const ClassDescriptor&)const;};
struct PropertyDescriptor;struct SignalSource {virtual ~SignalSource();void*signals;};
struct DescribedBase:SignalSource {ClassDescriptor*descriptor;};
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
template<class T> boost::shared_ptr<T> __cdecl shared_from(T*);
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
class Instance:public GuidItem<Instance>,public AbstractFactoryProduct<Instance>,public Reflection::DescribedBase,public Debugable,
 public Notifier<Instance,ChildAdded>,public Notifier<Instance,ChildRemoved>,public Notifier<Instance,DescendentAdded>,public Notifier<Instance,DescendentRemoving>,public Notifier<Instance,AncestorChanged>,public Notifier<Instance,PropertyChanged>,public boost::enable_shared_from_this<Instance>,public boost::noncopyable {public:
 static boost::shared_ptr<Instance>create(const Name&);
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
 void raisePropertyChanged(const Reflection::PropertyDescriptor&);const Reflection::ClassDescriptor&getDesc()const{return *descriptor;}void setParent(Instance*);
};

class Service {};
class StandardOut {public:static boost::shared_ptr<StandardOut>singleton();void __cdecl print(int,const char*,...);};
namespace Reflection {struct Property {const PropertyDescriptor*descriptor;DescribedBase*instance;Property(const PropertyDescriptor&d,DescribedBase*i):descriptor(&d),instance(i){}};}
namespace Network {
struct Settings {static Settings&singleton();char pad[0x131];bool printInstances;};
class IdSerializer:public Instance {public:void deserializeId(RakNet::BitStream&,Guid::Data&);void resolvePendingBindings(Instance*,Guid::Data);};
class PluginInterface {public:virtual~PluginInterface();};
struct ReplicationData {boost::shared_ptr<Instance>instance;boost::signals::connection added,changed;bool flag;};
class Replicator:public IdSerializer,public PluginInterface {
public:
 virtual bool wantReplicate(const Instance*)const;
 void readInstanceNew(RakNet::BitStream&);
 ReplicationData&addReplicationData(boost::shared_ptr<Instance>,bool);
 void deserializeProperties(RakNet::BitStream&,Instance*);
 void deserializeValue(RakNet::BitStream&,Reflection::Property&);
 void onPropertyChanged(boost::shared_ptr<Instance>,const Reflection::PropertyDescriptor*);
};

class SystemAddress {public:const char*ToString(bool)const;};
struct Placeholder {};
namespace SlotDetail {
class X;union FunctionBuffer {void*obj_ptr;const void*const_obj_ptr;void(*func_ptr)();struct BoundMember {void(X::*memfunc_ptr)(int);void*obj_ptr;}bound_memfunc_ptr;char data;};
struct Function {void*vtable;FunctionBuffer functor;};struct SlotBase {boost::shared_ptr<void>data;};
}
struct BoundChanged {
 typedef void(Replicator::*Method)(boost::shared_ptr<Instance>,const Reflection::PropertyDescriptor*);
 Method method;Replicator*owner;boost::shared_ptr<Instance>instance;Placeholder argument;
};
BoundChanged __cdecl bindChanged(BoundChanged::Method,Replicator*,boost::shared_ptr<Instance>,Placeholder);
struct ChangedSlot:SlotDetail::SlotBase {SlotDetail::Function slot_function;ChangedSlot(const BoundChanged&);~ChangedSlot();};
struct ChangedSignal {boost::signals::connection connect(Reflection::SignalSource*,const ChangedSlot&,int);};
extern ChangedSignal propertyChangedSignal;
extern const Reflection::PropertyDescriptor parentProperty;
extern Placeholder firstArgument;
void __cdecl reportNullBinding(Guid::Data,const char*,const Name*);
struct ReplicatorStats {};
template<class T>inline T&field(void*p,unsigned off){return *reinterpret_cast<T*>(static_cast<char*>(p)+off);}
RakNet::BitStream&operator>>(RakNet::BitStream&,bool&);
void Replicator::readInstanceNew(RakNet::BitStream&stream){
 unsigned startBits=field<unsigned>(&stream,8);
 Guid::Data id;
 deserializeId(stream,id);
 unsigned index=0;
 stream.ReadBits(reinterpret_cast<unsigned char*>(&index),field<int>(this,0x2bec),true);
 const Reflection::ClassDescriptor*desc=field<std::vector<const Reflection::ClassDescriptor*> >(this,0x2bd4)[index];
 if(Settings::singleton().printInstances)
  StandardOut::singleton()->print(1,"Replication: %s:%s << %s",desc->name->c_str(),id.readableString(4).c_str(),field<SystemAddress>(this,0x2d54).ToString(true));
 boost::shared_ptr<Instance>instance;
 Instance*existing;
 if(GuidItem<Instance>::find(id,existing)){
  if(!existing)reportNullBinding(id,field<const char*>(this,0x2d5c),field<const Name*>(this,0x2d60));
  instance=shared_from(existing);
  if(instance->getDesc()!=*desc)
   StandardOut::singleton()->print(3,"Replication: Bad re-binding %s-%s << %s, %s-%s",desc->name->c_str(),id.readableString(4).c_str(),field<SystemAddress>(this,0x2d54).ToString(true),instance->getClassName().c_str(),id.readableString(4).c_str());
 }else{
  instance=Instance::create(*desc->name);
  if(!instance){
   std::string message=G3D::format("Replication: Can't create object of type %s",desc->name->c_str());
   StandardOut::singleton()->print(3,message.c_str());
   throw std::runtime_error(message);
  }
  instance->unregisterGuid();
  instance->guid.assign(id);
  instance->registerGuid();
  instance->onGuidChanged();
 }
 ReplicationData&data=addReplicationData(instance,false);
 stream>>data.flag;
 deserializeProperties(stream,instance.get());
 bool blocked=!wantReplicate(instance.get());
 if(blocked)
  StandardOut::singleton()->print(2,"Replication illegal instance: %s:%s << %s",desc->name->c_str(),id.readableString(4).c_str(),field<SystemAddress>(this,0x2d54).ToString(true));
 if(dynamic_cast<Service*>(instance.get())){Guid::Data ignoredParent;deserializeId(stream,ignoredParent);}
 else if(blocked){Guid::Data ignoredParent;deserializeId(stream,ignoredParent);}
 else{
  data.changed=propertyChangedSignal.connect(instance.get(),bindChanged(&Replicator::onPropertyChanged,this,instance,firstArgument),0);
  Reflection::Property property(parentProperty,instance.get());
  deserializeValue(stream,property);
 }
 if(!blocked)resolvePendingBindings(instance.get(),id);
 unsigned endBits=field<unsigned>(&stream,8);
 if(field<boost::shared_ptr<ReplicatorStats> >(this,0x2b88).get()){++field<unsigned>(field<boost::shared_ptr<ReplicatorStats> >(this,0x2b88).get(),0x174);field<unsigned>(field<boost::shared_ptr<ReplicatorStats> >(this,0x2b88).get(),0x178)+=endBits-startBits;}
 field<const Name*>(this,0x2d60)=desc->name;
}
}
}
