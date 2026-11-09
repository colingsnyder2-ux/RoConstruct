// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <set>
#include <list>
#include <intrin.h>
#include <utility>
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
    template<class Y> __declspec(noinline) explicit shared_count(Y*p):pi_(0){try{pi_=new sp_counted_impl_p<Y>(p);}catch(...){delete p;throw;}}
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
    template<class Y> explicit shared_ptr(Y*p):px(p),pn(p){detail::sp_enable_shared_from_this(pn,p,p);}
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

template<class T>struct ScopedPtr {T*pointer;T&operator*()const{return *pointer;}};
struct CodeProfiler;
// Constructor stores profiler at 0, previous TLS value at 4, flag at 8 and time at 0x10.
struct ProfileMark {CodeProfiler*section;void*previous;bool frameTick;double startTime;ProfileMark(CodeProfiler&,bool);~ProfileMark();};
class __multiple_inheritance Replicator;
class Instance;
struct MemberFunction {
 typedef void(Replicator::*Function)(boost::shared_ptr<Instance>);
 Function function;
 void operator()(Replicator*,boost::shared_ptr<Instance>)const;
};
struct Placeholder {};
struct Visitor {MemberFunction function;Replicator*owner;Placeholder placeholder;void operator()(const boost::shared_ptr<Instance>&p)const{function(owner,p);}};
class Instance {public:void visitChildren(Visitor)const;};
class Item {public:virtual ~Item();Replicator&replicator;};
class NewInstanceItem:public Item {boost::shared_ptr<Instance>instance;public:NewInstanceItem(Replicator&,const boost::shared_ptr<Instance>&);};
// RTTI places PluginInterface at 0x2b74; the primary IdSerializer prefix occupies that extent.
struct PrimaryInterface {virtual ~PrimaryInterface();char opaque[0x2b74-4];};
struct SecondaryInterface {virtual ~SecondaryInterface();};
class Replicator:public PrimaryInterface,public SecondaryInterface {
public:
 virtual ~Replicator();
 virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();
 virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();
 virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();
 virtual void slot16();virtual void slot17();virtual bool wantReplicate(const Instance*)const;
 char prefix[0x2c38-0x2b78];std::set<const Instance*>pendingNew;
 char reserved[0x2c74-0x2c58];std::list<boost::shared_ptr<Item> >pendingItems;
 char reserved90[0x2d1c-0x2c90];ScopedPtr<CodeProfiler>profileA;ScopedPtr<CodeProfiler>profileB;
 void addReplicationData(boost::shared_ptr<Instance>,bool);
 void onDescendentAdded(boost::shared_ptr<Instance>);
};
void Replicator::onDescendentAdded(boost::shared_ptr<Instance>instance){
 ProfileMark markA(*profileA,false);
 ProfileMark markB(*profileB,false);
 if(!wantReplicate(instance.get()))return;
 const Instance*key=instance.get();
 if(pendingNew.find(key)==pendingNew.end()){
  addReplicationData(instance,true);
  pendingItems.push_back(boost::shared_ptr<Item>(new NewInstanceItem(*this,instance)));
  Visitor visitor;visitor.function.function=&Replicator::onDescendentAdded;visitor.owner=this;
  instance->visitChildren(visitor);
 }
}
