// from server: 100% by king_originala
// from server: 93% by colin
// from server: 91% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: xtp-11.2.2-shared-mfc roc_king_originala_tree_timer_b766cf8d251287ae.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#define _AFXDLL 1
#define _XTP_STATICLINK 1
#include <afxwin.h>
#include <afxext.h>
#include <XTToolkitPro.h>
#include <map>
#include <set>
#include <intrin.h>
#include <typeinfo>
#include <stdexcept>
namespace boost {namespace detail {
class sp_counted_base {
 sp_counted_base(const sp_counted_base&);
 sp_counted_base&operator=(const sp_counted_base&);
 long use_count_,weak_count_;
public:
 sp_counted_base():use_count_(1),weak_count_(1){}
 virtual ~sp_counted_base(){}
 virtual void dispose()=0;
 virtual void destroy(){delete this;}
 virtual void*get_deleter(const std::type_info&)=0;
 void add_ref_copy(){_InterlockedIncrement(&use_count_);}
 void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
 void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
class shared_count {
 sp_counted_base*pi_;
public:
 shared_count():pi_(0){}
 shared_count(const shared_count&r):pi_(r.pi_){if(pi_)pi_->add_ref_copy();}
 ~shared_count(){if(pi_)pi_->release();}
 friend inline bool operator<(shared_count const&a,shared_count const&b){return std::less<sp_counted_base*>()(a.pi_,b.pi_);}
};
}
template<class T>class shared_ptr {
 T*px;detail::shared_count pn;
public:
 shared_ptr():px(0),pn(){}
 shared_ptr(const shared_ptr&r):px(r.px),pn(r.pn){}
 template<class Y>shared_ptr(const shared_ptr<Y>&r):px(r.px),pn(r.pn){}
 T*get()const{return px;}
 template<class Y>bool _internal_less(shared_ptr<Y>const&r)const{return pn<r.pn;}
 template<class Y>friend class shared_ptr;
};
}
namespace boost {template<class T,class U>inline bool operator<(shared_ptr<T>const&a,shared_ptr<U>const&b){return a._internal_less(b);}}
namespace boost {namespace noncopyable_ {class noncopyable {protected:noncopyable(){}~noncopyable(){}private:noncopyable(const noncopyable&);const noncopyable&operator=(const noncopyable&);};}typedef noncopyable_::noncopyable noncopyable;
class condition;struct xtime;
class thread_exception:public std::exception {protected:thread_exception();thread_exception(int);public:~thread_exception()throw();int native_error()const;private:int m_sys_err;};
class lock_error:public thread_exception {public:lock_error();lock_error(int);~lock_error()throw();virtual const char*what()const throw();};
namespace detail {namespace thread {
template <typename Mutex>
class lock_ops : private noncopyable
{
private:
    lock_ops() { }

public:
    typedef typename Mutex::cv_state lock_state;

    static void lock(Mutex& m)
    {
        m.do_lock();
    }
    static bool trylock(Mutex& m)
    {
        return m.do_trylock();
    }
    static bool timedlock(Mutex& m, const xtime& xt)
    {
        return m.do_timedlock(xt);
    }
    static void unlock(Mutex& m)
    {
        m.do_unlock();
    }
    static void lock(Mutex& m, lock_state& state)
    {
        m.do_lock(state);
    }
    static void unlock(Mutex& m, lock_state& state)
    {
        m.do_unlock(state);
    }
};

template <typename Mutex>
class scoped_lock : private noncopyable
{
public:
    typedef Mutex mutex_type;

    explicit scoped_lock(Mutex& mx, bool initially_locked=true)
        : m_mutex(mx), m_locked(false)
    {
        if (initially_locked) lock();
    }
    ~scoped_lock()
    {
        if (m_locked) unlock();
    }

    void lock()
    {
        if (m_locked) throw lock_error();
        lock_ops<Mutex>::lock(m_mutex);
        m_locked = true;
    }
    void unlock()
    {
        if (!m_locked) throw lock_error();
        lock_ops<Mutex>::unlock(m_mutex);
        m_locked = false;
    }

    bool locked() const { return m_locked; }
    operator const void*() const { return m_locked ? this : 0; }

private:
    friend class boost::condition;

    Mutex& m_mutex;
    bool m_locked;
};

}}class recursive_mutex:private noncopyable {public:friend class detail::thread::lock_ops<recursive_mutex>;typedef detail::thread::scoped_lock<recursive_mutex> scoped_lock;recursive_mutex();~recursive_mutex();private:typedef std::size_t cv_state;void do_lock();void do_unlock();void do_lock(cv_state&);void do_unlock(cv_state&);void*m_mutex;bool m_critical_section;unsigned long m_count;};}

namespace RBX {class Instance;class PropertyChanged;struct ChildAdded;struct ChildRemoved;namespace Reflection {class ClassDescriptor;}
template<class C,class E>class __declspec(novtable) Listener {protected:virtual void onEvent(const C*,E)=0;Listener&operator=(const Listener&);virtual~Listener(){}};
}

namespace RBX {class DataModel;class Selection;}
class CRobloxTreeCtrlNode;
class CRobloxTreeCtrl:public CXTTreeCtrl {
public:
 virtual RBX::Selection*getSelection()=0;
 virtual boost::shared_ptr<RBX::DataModel>getDataModel()=0;
 virtual void onNodeCreated(CRobloxTreeCtrlNode*)=0;
 virtual void onNodeChanged(CRobloxTreeCtrlNode*)=0;
 virtual void onNodeDeleted(CRobloxTreeCtrlNode*)=0;
 virtual void refreshTree();
 CRobloxTreeCtrlNode*root;
 std::map<RBX::Instance*,CRobloxTreeCtrlNode*>nodes;
 bool changing;
 CImageList images;
 boost::recursive_mutex mutex;
};
struct NativeTreeWriteGuard {
 boost::shared_ptr<boost::recursive_mutex>mutex;
 boost::recursive_mutex::scoped_lock*lock;
 NativeTreeWriteGuard(boost::shared_ptr<const RBX::DataModel>);
 ~NativeTreeWriteGuard();
};
extern int nativeTreeSortPriority(RBX::Instance*);
class CRobloxTreeCtrlNode:
 public RBX::Listener<RBX::Instance,RBX::PropertyChanged>,
 public RBX::Listener<RBX::Instance,RBX::ChildAdded>,
 public RBX::Listener<RBX::Instance,RBX::ChildRemoved> {
public:
 boost::shared_ptr<RBX::Instance>instance;
 std::map<RBX::Instance*,CRobloxTreeCtrlNode*>children;
 std::set<CRobloxTreeCtrlNode*>removedChildren;
 bool expanded:1;
 bool expandedOnce:1;
 bool changing;
 CRobloxTreeCtrl*tree;
 CRobloxTreeCtrlNode*parent;
 std::set<boost::shared_ptr<RBX::Instance> >pendingChildren;
 HTREEITEM item;
 int priority;
 const RBX::Reflection::ClassDescriptor*descriptor;
 CRobloxTreeCtrlNode(CRobloxTreeCtrlNode*,boost::shared_ptr<RBX::Instance>,CRobloxTreeCtrl*);
 virtual~CRobloxTreeCtrlNode();
 virtual void onEvent(const RBX::Instance*,RBX::PropertyChanged);
 virtual void onEvent(const RBX::Instance*,RBX::ChildAdded);
 virtual void onEvent(const RBX::Instance*,RBX::ChildRemoved);
 virtual void updateSelection();
 virtual void createItem();
 virtual void updateExpansion(int);
 virtual void getDisplayInfo(NMTVDISPINFOA*);
 virtual HTREEITEM insertItem();
 void prepareTreeItem();void updateTreeItem();void finishTreeItem();
};

struct NativeScopedFlag {
 bool&flag;bool previous;
 NativeScopedFlag(bool&v,bool value):flag(v){previous=v;v=value;}
 ~NativeScopedFlag(){flag=previous;}
};
class NativeSelectionTimer:public CRobloxTreeCtrl {
public:void refreshPending();void onTimer(UINT_PTR);
};
void NativeSelectionTimer::onTimer(UINT_PTR argument){
 CRobloxTreeCtrlNode*selected=0;
 typedef std::set<CRobloxTreeCtrlNode*> DirtyNodes;
 DirtyNodes&dirty=*reinterpret_cast<DirtyNodes*>(reinterpret_cast<char*>(this)+0x104);
 boost::detail::thread::lock_ops<boost::recursive_mutex>::lock(mutex);
 if(dirty.size()>0)selected=*dirty.begin();
 boost::detail::thread::lock_ops<boost::recursive_mutex>::unlock(mutex);
 if(selected){
  NativeScopedFlag outer(*reinterpret_cast<bool*>(reinterpret_cast<char*>(this)+0xe1),true);
  selected->prepareTreeItem();
  selected->updateSelection();
  {NativeScopedFlag inner(*reinterpret_cast<bool*>(reinterpret_cast<char*>(this)+0xe0),true);selected->updateTreeItem();}
  selected->finishTreeItem();
  {boost::recursive_mutex::scoped_lock lock(mutex);if(selected->pendingChildren.empty())onNodeDeleted(selected);}
 }
 refreshPending();
 CXTTreeCtrl::OnTimer(argument);
}
