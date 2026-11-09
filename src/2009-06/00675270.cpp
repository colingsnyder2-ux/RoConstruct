// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
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
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr(const shared_ptr&);
    T* operator->() const { return px; }
    T* get() const { return px; }
};
}
namespace std {
template<class T> class vector {
public:
    void push_back(const T&);
};
}
namespace RBX {
class Instance { public: virtual ~Instance(); };
class Team : public Instance { };
boost::shared_ptr<Instance> shared_from(Instance*);
template<class T> class copy_on_write_ptr {
public:
    boost::shared_ptr<T>& write();
};
class Teams : public Instance {
protected:
    virtual void onChildAdded(Instance* child);
    char pad[0x88];
    copy_on_write_ptr<std::vector<boost::shared_ptr<Instance> > > teams;
};
void Teams::onChildAdded(Instance* child)
{
    if (dynamic_cast<Team*>(child))
    {
        boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > >& myTeams = teams.write();
        myTeams->push_back(shared_from(child));
    }
}
}
