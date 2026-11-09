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
    __declspec(noinline) shared_count& operator=(const shared_count& r){sp_counted_base* tmp=r.pi_;if(tmp!=pi_){if(tmp)_InterlockedIncrement(&tmp->use_count_);if(pi_)pi_->release();pi_=tmp;}return *this;}
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

namespace RBX {
class Instance;namespace Network {class Player;}
struct ChildAdded {};struct ChildRemoved {};struct DescendantAdded {};struct DescendantRemoving {};
namespace Network {struct CharacterAdded {};struct CharacterRemoving {};}
template<class Source,class Event>struct Listener {virtual void onEvent(const Source*,Event)=0;virtual ~Listener(){}};
template<class Source,class Event>struct Notifier {virtual ~Notifier();char storage[0x20-4];void addListener(Listener<Source,Event>*)const;template<class T>static void connect(const T& source,Listener<Source,Event>* listener){if(source)source->Notifier<Source,Event>::addListener(listener);}};
struct InstancePrefix {virtual ~InstancePrefix();char prefix[0x24-4];};
class Instance:public InstancePrefix,public Notifier<Instance,ChildAdded>,public Notifier<Instance,ChildRemoved> {char gap[0x130-0x64];};
namespace Network {class Player:public Instance,public Notifier<Player,CharacterAdded>,public Notifier<Player,CharacterRemoving> {};}
struct PanelBase {virtual ~PanelBase();char prefix[0x168-4];};
struct LocalBackpack:PanelBase,
 Listener<Instance,ChildAdded>,Listener<Instance,ChildRemoved>,
 Listener<Instance,DescendantAdded>,Listener<Instance,DescendantRemoving>,
 Listener<Network::Player,Network::CharacterAdded>,Listener<Network::Player,Network::CharacterRemoving> {
 boost::shared_ptr<Instance> players;
 boost::shared_ptr<Network::Player> localPlayer;
 void onLocalPlayerAdded(Network::Player*);
};
boost::shared_ptr<Network::Player> __cdecl sharedFrom(Network::Player*);
void LocalBackpack::onLocalPlayerAdded(Network::Player* player){
 localPlayer=sharedFrom(player);
 Notifier<Instance,ChildAdded>::connect(localPlayer,this);
 Notifier<Instance,ChildRemoved>::connect(localPlayer,this);
 Notifier<Network::Player,Network::CharacterAdded>::connect(localPlayer,this);
 Notifier<Network::Player,Network::CharacterRemoving>::connect(localPlayer,this);
}
}
