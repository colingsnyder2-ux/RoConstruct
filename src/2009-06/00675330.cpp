// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <vector>
#include <algorithm>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    shared_ptr();
    shared_ptr(const shared_ptr&);
    shared_ptr& operator=(const shared_ptr&);
    ~shared_ptr() { if (pn) pn->release(); }
    T* operator->() const { return px; }
    T* get() const { return px; }
};
template<class T, class U> inline bool operator==(const shared_ptr<T>& a, const shared_ptr<U>& b) { return a.get() == b.get(); }
}
namespace RBX {
class Instance {
public:
    virtual ~Instance();
};
class Team : public Instance {};
boost::shared_ptr<Instance> shared_from(Instance* p);
template<class T> class copy_on_write_ptr {
public:
    boost::shared_ptr<T>& write();
};
class Teams : public Instance {
public:
    char pad[0x88];
    copy_on_write_ptr<std::vector<boost::shared_ptr<Instance> > > teams;
protected:
    virtual void onChildRemoving(Instance* child);
};
void Teams::onChildRemoving(Instance* child)
{
    if (dynamic_cast<Team*>(child))
    {
        boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > >& myTeams = teams.write();
        myTeams->erase(std::find(myTeams->begin(), myTeams->end(), shared_from(child)));
    }
}
}
