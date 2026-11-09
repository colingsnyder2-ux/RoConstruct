// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <vector>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace boost {
namespace noncopyable_ { class noncopyable { protected: noncopyable() {} ~noncopyable() {} }; }
typedef noncopyable_::noncopyable noncopyable;
struct sp_counted_base;
namespace detail {
class shared_count { public: sp_counted_base* pi_; shared_count() : pi_(0) {} ~shared_count(); };
class weak_count { public: sp_counted_base* pi_; weak_count() : pi_(0) {} ~weak_count(); };
}
template<class T> class weak_ptr {
public:
    T* px; detail::weak_count pn;
    weak_ptr() : px(0), pn() {}
};
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
};
template<class T> class enable_shared_from_this {
protected:
    enable_shared_from_this() {}
    ~enable_shared_from_this() {}
public:
    weak_ptr<T> _internal_weak_this;
};
}
namespace RBX {
class Name;
class Guid {
public:
    const Name* scope;
    unsigned int index;
    Guid();
};
template<class T> class __declspec(novtable) GuidItem {
public:
    boost::shared_ptr<void> registry;
    Guid guid;
    virtual ~GuidItem() {}
};
class Object {
public:
    virtual ~Object() {}
};
template<class T> class Creatable : public Object {
};
template<class T> class AbstractFactoryProduct : public Creatable<T> {
public:
    virtual ~AbstractFactoryProduct() {}
};
namespace Reflection {
class EventSource {
public:
    virtual ~EventSource();
};
class ClassDescriptor;
class DescribedBase : public EventSource {
public:
    const ClassDescriptor* descriptor;
    DescribedBase();
};
template<class C, const char** sName, class Base>
class __declspec(novtable) Described : public Base {
public:
    Described() {}
    virtual ~Described() {}
};
}
class __declspec(novtable) Debugable {
public:
    virtual ~Debugable() {}
};
template<class T> class Countable {
public:
    static volatile long count;
    Countable() { InterlockedIncrement(&count); }
    ~Countable() { InterlockedDecrement(&count); }
};
extern const char* sInstance;
class Instance;
typedef std::vector<boost::shared_ptr<Instance> > Instances;
class Instance
    : public boost::enable_shared_from_this<Instance>
    , public GuidItem<Instance>
    , public AbstractFactoryProduct<Instance>
    , public Reflection::Described<Instance, &sInstance, Reflection::DescribedBase>
    , public Debugable
    , public Countable<Instance>
    , boost::noncopyable
{
public:
    std::vector<int> assoc;
    Instance* parent;
    boost::shared_ptr<Instances> children;
    std::string name;
    bool archivable;
    bool flag2;
    boost::shared_ptr<void> a, b, c;
    Instance();
    virtual ~Instance();
};
Instance::Instance()
    : parent(0)
    , name("Instance")
    , archivable(true)
    , flag2(false)
{
}
}
