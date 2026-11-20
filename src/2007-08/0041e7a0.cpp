// from server: 100% by Intel_Inside
// roc 2007-08 0041e7a0  unit: RBX::VInstance::?$MarshaledListener  size: 155 bytes
#include <intrin.h>

namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    long use_count_;
    long weak_count_;
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_) _InterlockedIncrement(&pi_->use_count_); }
    ~shared_count();
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
}

namespace RBX {
class Instance;

struct Event {
    boost::shared_ptr<Instance> a;
    boost::shared_ptr<Instance> b;
    ~Event();
};

struct Queue {
    void push(void* const& item);
};

struct Item;
struct Signal {
    void post(Item* item);
};

class MarshaledListener;

struct Item {
    char data[0x20];
    Item(MarshaledListener* owner, int tag, Event e);
};

class MarshaledListener {
public:
    virtual void onEvent(int tag, Event e) throw();
    Queue queue;
    char pad[0x18 - 4 - sizeof(Queue)];
    Signal* signal;
};

void MarshaledListener::onEvent(int tag, Event e) throw()
{
    Item* item = new Item(this, tag, e);
    queue.push(item);
    signal->post(item);
}
}
