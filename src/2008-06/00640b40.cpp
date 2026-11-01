// from server: 100% by king_originala
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
#include <algorithm>
struct Instance;struct Part;
typedef std::vector<boost::shared_ptr<Instance> > Instances;
typedef std::vector<Part*> Parts;
struct Snapshot {boost::shared_ptr<Instances> object;const Instances*operator->()const{return object.get();}};
struct Selection {char prefix[0x154];Snapshot selected;Instances::const_iterator begin()const{return selected->begin();}Instances::const_iterator end()const{return selected->end();}};
struct CachedSelection {Instance* context;boost::shared_ptr<Selection> selected;CachedSelection(Instance*p):context(p){}Selection*get(int);};
void __cdecl collectPart(boost::shared_ptr<Instance>,Parts*);
struct Callback {void(__cdecl* function)(boost::shared_ptr<Instance>,Parts*);Parts* parts;Callback(void(__cdecl*f)(boost::shared_ptr<Instance>,Parts*),Parts*p):function(f),parts(p){}void operator()(const boost::shared_ptr<Instance>&p){function(p,parts);}};
struct Vec3 {float x,y,z;Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct Extents {Vec3 min,max;Extents&operator=(const Extents&v){min=v.min;max=v.max;return *this;}};
Extents __cdecl worldExtents(const Parts&);
struct AxisMoveTool {char prefix[0x18];Instance* workspace;bool extents(Extents&);};
bool AxisMoveTool::extents(Extents& out){
 CachedSelection selection(workspace);
 Parts parts;
 std::for_each(selection.get(1)->begin(),selection.get(1)->end(),Callback(collectPart,&parts));
 if(parts.size()>0){out=worldExtents(parts);return true;}
 return false;
}
