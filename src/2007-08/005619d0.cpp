// from server: 100% by Intel_Inside
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
#include <intrin.h>
#pragma intrinsic(_InterlockedDecrement)

namespace boost {

namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;            // +4
    long weak_count_;           // +8
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
};

class shared_count {
    sp_counted_base* pi_;
public:
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);     // 0x402a60
};
}

template<class T> class shared_ptr {
public:
    T* get() const { return px; }
    T* operator->() const { return px; }
    T* px;
    detail::shared_count pn;
};

struct once_flag { long epoch; };
void call_once(void (*func)(), once_flag& flag);        // 0x725520

}

namespace RBX {

class Instance;

class Tool {
public:
    void setOwner(Instance* owner);                      // 0x541630
};

boost::shared_ptr<Tool> createTool();                    // 0x43de50
void initToolIndex();                                     // 0x5588d0
extern boost::once_flag toolIndexFlag;                    // 0x8c1f1c
unsigned int toolIndex();                                 // 0x5578c0

class Instance {
    int pad[0x130 / 4];
    std::vector< boost::shared_ptr<Tool> > products;      // _Myfirst at +0x134 (VS2005 vector keeps its allocator first)
public:
    Tool* findTool();                                     // 0x55a490
    Tool* create();
};

Tool* Instance::create()
{
    Tool* result = findTool();
    if (result == 0) {
        boost::shared_ptr<Tool> tool = createTool();
        result = tool.get();
        boost::call_once(&initToolIndex, toolIndexFlag);
        products[toolIndex()] = tool;
        result->setOwner(this);
    }
    return result;
}

}
