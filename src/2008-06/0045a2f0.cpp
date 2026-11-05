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

struct Listener {virtual ~Listener();};
struct Notifier {char storage[32];void removeListener(Listener*)const;};
struct Service {char prefix[0x150];Notifier notifier;};
struct Model {
 char prefix[0x150];Notifier first,second;
 Service* service();
};
struct Request {char storage[12];Request(boost::shared_ptr<Model>);~Request();};
struct Connection {virtual void reserved();virtual ~Connection();};
struct Owned {
 Connection* p;
 void reset(){Connection* old=p;p=0;delete old;}
};
struct ViewPrefix {virtual ~ViewPrefix();char prefix[0xa0-4];Listener a,b;};
struct CRobloxView:ViewPrefix,Listener {
 char pad1[0x170-0xac];
 boost::shared_ptr<Model> model;
 char pad2[0x1dc-0x178];
 Owned one,two,three,four,five;
 boost::shared_ptr<Model> getModel()const;
 void detach();
};
static Service* findService(Model* m){return m?m->service():0;}
void CRobloxView::detach(){
 Request request(model);
 one.reset();two.reset();three.reset();four.reset();five.reset();
 Listener* first=this?&a:0;
 if(model.get())model->first.removeListener(first);
 Listener* second=&b;
 if(model.get())model->second.removeListener(second);
 Service* current=findService(getModel().get());
 if(current)current->notifier.removeListener(static_cast<Listener*>(this));
}
