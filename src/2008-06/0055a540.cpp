// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <string>
#include <vector>
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
class shared_count {
    sp_counted_base* pi_;
public:
    shared_count() : pi_(0) {}
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
class weak_count {
    sp_counted_base* pi_;
public:
    weak_count() : pi_(0) {}
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class shared_ptr { T* px; detail::shared_count pn; };
template<class T> class weak_ptr { T* px; detail::weak_count pn; };
template<class T> class enable_shared_from_this {
protected:
    enable_shared_from_this() {}
    ~enable_shared_from_this() {}
    mutable weak_ptr<T> _internal_weak_this;
};
}
namespace RBX {
class Instance;
class Listener;
template<int N>
class __declspec(novtable) Notifier {
public:
    virtual void notifierVirtual();
private:
    std::vector<Listener*> listeners;
    int flags;
};
class DescribedBase {
public:
    virtual ~DescribedBase();
    char pad[0x10 - 4];
};
class EventSource {
public:
    virtual ~EventSource() {}
};
class SourceA { public: virtual void a(); char pad[8]; };
class SourceB { public: virtual void b(); };
class SignalSource : public SourceA, public SourceB {
public:
    ~SignalSource();
};
class ChildList { char data[0x1c]; public: ~ChildList(); };
class Instance : public boost::enable_shared_from_this<Instance>,
                 public DescribedBase,
                 public EventSource,
                 public SignalSource,
                 public Notifier<0>, public Notifier<1>, public Notifier<2>,
                 public Notifier<3>, public Notifier<4>, public Notifier<5>
{
public:
    virtual ~Instance();
    static long count;
private:
    ChildList children;                  // 0xec
    boost::shared_ptr<Instance> parent;  // 0x108
    std::string name;                    // 0x110
};
Instance::~Instance()
{
    InterlockedDecrement(&count);
}
}
