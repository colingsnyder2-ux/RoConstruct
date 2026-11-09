// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// Minimal measured ABI views; TrackedInstance and signal labels are descriptive.
// Native Boost.Signals comparison bases account for connection.con at +4.
// Native callbacks/container APIs plus the full target establish record and signal signatures.
#include <map>
#include <intrin.h>
#include <utility>
#include <stddef.h>
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
struct connection:private less_than_comparable1<connection>,private equality_comparable1<connection> {
 shared_ptr<basic_connection>con;bool controlling_connection;
 connection():con(),controlling_connection(false){}connection(const connection&);~connection();connection&operator=(const connection&);void disconnect()const;
 bool connected()const{return con.get()&&con->signal_disconnect;}
};
}
}
namespace RBX {
namespace Reflection {struct PropertyDescriptor;struct SignalSource {virtual ~SignalSource();void*signals;};}
struct InstancePrefix {virtual ~InstancePrefix();char opaque[0x14-4];};
struct Instance:InstancePrefix,Reflection::SignalSource {};
namespace Network {
struct TrackedInstance {
 boost::shared_ptr<Instance>instance;boost::signals::connection added,changed;bool flag;
 TrackedInstance():instance(),added(),changed(){}TrackedInstance(const TrackedInstance&);~TrackedInstance();
};
struct IdSerializerView {virtual ~IdSerializerView();char opaque[0x2b74-4];};
struct PluginInterfaceView {virtual ~PluginInterfaceView();};
struct Replicator:IdSerializerView,PluginInterfaceView {
 char opaque[0x2c38-0x2b78];typedef std::map<Instance*,TrackedInstance>RecordMap;RecordMap records;
 TrackedInstance&addReplicationData(boost::shared_ptr<Instance>,bool);
 void onDescendentAdded(boost::shared_ptr<Instance>);void onPropertyChanged(boost::shared_ptr<Instance>,const Reflection::PropertyDescriptor*);
};
struct Placeholder {};extern Placeholder firstArgument;
struct BoundAdded {
 typedef void(Replicator::*Method)(boost::shared_ptr<Instance>);Method method;Replicator*owner;Placeholder argument;
 BoundAdded(Method m,Replicator*p,Placeholder a):method(m),owner(p),argument(a){}
};
struct BoundChanged {
 typedef void(Replicator::*Method)(boost::shared_ptr<Instance>,const Reflection::PropertyDescriptor*);Method method;Replicator*owner;boost::shared_ptr<Instance>instance;Placeholder argument;
};
BoundChanged __cdecl bindChanged(BoundChanged::Method,Replicator*,boost::shared_ptr<Instance>,Placeholder);
namespace SlotDetail {
class X;union FunctionBuffer {void*obj_ptr;const void*const_obj_ptr;void(*func_ptr)();struct BoundMember {void(X::*memfunc_ptr)(int);void*obj_ptr;}bound_memfunc_ptr;char data;};
struct Function {void*vtable;FunctionBuffer functor;};struct SlotBase {boost::shared_ptr<void>data;};
}
struct AddedSlot:SlotDetail::SlotBase {SlotDetail::Function slot_function;AddedSlot(const BoundAdded&);~AddedSlot();};
struct ChangedSlot:SlotDetail::SlotBase {SlotDetail::Function slot_function;ChangedSlot(const BoundChanged&);~ChangedSlot();};
struct AddedSignal {boost::signals::connection connect(Reflection::SignalSource*,const AddedSlot&,int);};
struct ChangedSignal {boost::signals::connection connect(Reflection::SignalSource*,const ChangedSlot&,int);};
extern AddedSignal addedSignal;extern ChangedSignal changedSignal;
TrackedInstance&Replicator::addReplicationData(boost::shared_ptr<Instance>instance,bool listenChanges){
 std::pair<RecordMap::iterator,bool>result=records.insert(RecordMap::value_type(instance.get(),TrackedInstance()));
 if(result.second){
  TrackedInstance&data=result.first->second;data.instance=instance;data.flag=false;
  data.added=addedSignal.connect(instance.get(),BoundAdded(&Replicator::onDescendentAdded,this,firstArgument),0);
  if(listenChanges)data.changed=changedSignal.connect(instance.get(),bindChanged(&Replicator::onPropertyChanged,this,instance,firstArgument),0);
  return data;
 }else{
  TrackedInstance&data=result.first->second;
  if(!listenChanges)data.changed.disconnect();
  else if(!data.changed.connected())data.changed=changedSignal.connect(instance.get(),bindChanged(&Replicator::onPropertyChanged,this,instance,firstArgument),0);
  return data;
 }
}
}
}
typedef char connection_size[sizeof(boost::signals::connection)==16?1:-1];
typedef char connection_con[offsetof(boost::signals::connection,con)==4?1:-1];
typedef char record_size[sizeof(RBX::Network::TrackedInstance)==44?1:-1];
typedef char record_changed[offsetof(RBX::Network::TrackedInstance,changed)==0x18?1:-1];
typedef char record_flag[offsetof(RBX::Network::TrackedInstance,flag)==0x28?1:-1];
typedef char records_offset[offsetof(RBX::Network::Replicator,records)==0x2c38?1:-1];
typedef char added_slot_size[sizeof(RBX::Network::AddedSlot)==40?1:-1];
typedef char changed_bind_size[sizeof(RBX::Network::BoundChanged)==24?1:-1];
