// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    shared_ptr() : px(0), pn() {}
    T* get() const { return px; }
    T* operator->() const { return px; }
};

namespace RBX {
class Player {
public:
    char pad[0x1b4];
    int userId;
};

namespace Network {
class Players {
public:
    char pad[0x198];
    std::vector<shared_ptr<Player> >* players;
    shared_ptr<Player> playerFromId(int userId);
};

shared_ptr<Player> Players::playerFromId(int userId)
{
    for (std::vector<shared_ptr<Player> >::iterator it = players->begin(), end = players->end(); it != end; ++it)
    {
        if ((*it)->userId == userId)
            return *it;
    }
    return shared_ptr<Player>();
}
}
}
