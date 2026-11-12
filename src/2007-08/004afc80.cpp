// from server: 100% by EspClaude
// roc 2007-08 004afc80  unit: RBX::VMotor::?$FactoryProduct::Creator  size: 439 bytes
// Rewritten from the target disassembly (see roc check): per-index cache of
// shared_ptr<T> in a std::vector at this+0x130 (8-byte elements, sar 3),
// boost::call_once guarded accessors, function-local static bool.

#include <vector>

namespace boost {
typedef long once_flag;
void call_once(void (*func)(), once_flag& flag);

namespace detail {
class shared_count {
public:
    void* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r);
    ~shared_count();
    shared_count& operator=(const shared_count& r);
};
}
}

namespace RBX {

class Motor;
class Context;

class MotorPtr {
public:
    Motor* px;
    boost::detail::shared_count pn;
    MotorPtr() : px(0), pn() {}
    MotorPtr(const MotorPtr& r) : px(r.px), pn(r.pn) {}
    ~MotorPtr();
    Motor* get() const { return px; }
};

extern boost::once_flag indexFlag;
void initIndex();
unsigned int currentIndex();

extern boost::once_flag contextFlag;
void initContext();
Context* contextImpl();
Context* defaultContext();

inline unsigned int getIndex()
{
    boost::call_once(&initIndex, indexFlag);
    return currentIndex();
}

inline Context* getContext()
{
    boost::call_once(&initContext, contextFlag);
    return contextImpl();
}

class MotorCreator {
public:
    char pad[0x130];
    std::vector<MotorPtr> cache;
    MotorPtr create(Context* context) const;
    Motor* get();
};

Motor* MotorCreator::get()
{
    unsigned int index = getIndex();
    if (index + 1 > cache.size()) {
        cache.resize(index + 1);
    } else {
        Motor* existing = cache[index].get();
        if (existing)
            return existing;
    }
    static bool isDefault = (getContext() == defaultContext());
    if (isDefault)
        return 0;
    MotorPtr result = create(getContext());
    if (!result.get())
        return 0;
    Motor* motor = result.get();
    cache[index] = result;
    return motor;
}

}
