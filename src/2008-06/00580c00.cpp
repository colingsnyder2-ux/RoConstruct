// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <exception>
namespace RBX {
class Instance;
bool checkA(Instance* instance, int role);
bool checkB(Instance* instance, int role);
class runtime_error : public std::exception
{
    std::string message;
public:
    runtime_error(const std::string& m);
};
static __declspec(noinline) void checkPermissions(Instance* instance)
{
    if (checkA(instance, 1) && !checkB(instance, 1))
    {
        std::string msg("Insufficinet permissions");
        throw runtime_error(msg);
    }
}
}

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

#include <vector>
namespace RBX {
class Instance {};
typedef std::vector<boost::shared_ptr<Instance> > Instances;
struct Selection {
 char pad[0x154];
 const Instances* selected;
 Instances::const_iterator begin()const{return selected->begin();}
 Instances::const_iterator end()const{return selected->end();}
 void setSelection(Instance*);
};
struct Workspace {boost::shared_ptr<Instance> group(Instances::const_iterator,Instances::const_iterator);};
struct History {void record(int);};
struct Context {Selection* selection();History* history();};
struct Name {int id;std::string text;const char* c_str()const{return text.c_str();}};
struct IDataState {virtual void setDirty(bool)=0;};
void __cdecl trackVerb(const char*,Workspace*);
struct GroupSelectionVerb {
 void* table;
 const Name* name;
 void* unused;
 Workspace* workspace;
 char pad[0x10];
 Context* context;
 void doIt(IDataState*);
};
void GroupSelectionVerb::doIt(IDataState* state){
 checkPermissions(reinterpret_cast<Instance*>(context));
 Selection* selection=context?context->selection():0;
 Instance* group=workspace->group(selection->begin(),selection->end()).get();
 selection->setSelection(group);
 History* history=context?context->history():0;
 history->record(8);
 Workspace* currentWorkspace=workspace;
 trackVerb(name->c_str(),currentWorkspace);
 state->setDirty(true);
}
}
