// from server: 100% by tester
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Value {
    virtual void release(int) = 0;
    virtual void reserved() = 0;
    virtual Value* clone() = 0;
};

struct Control {
    void* table;
    volatile long references;
};

struct Shared {
    void* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control) {
        volatile long* count = &control->references;
        _InterlockedExchangeAdd(count, 1);
    }
}

struct Argument {
    unsigned long type;
    Value* value;

    Argument(const Argument&);
    ~Argument();
    Value* copyValue() const;
    const double& number();
    const Shared& shared();
};

inline Value* Argument::copyValue() const
{
    Value* source = value;
    if (source)
        return source->clone();
    return 0;
}

inline Argument::Argument(const Argument& other)
    : type(other.type), value(other.copyValue())
{
}

inline Argument::~Argument()
{
    Value* source = value;
    if (source)
        source->release(1);
}

struct Arguments {
    virtual void reserved() = 0;
    virtual void get(int, Argument&) = 0;
};

namespace RBX { namespace Reflection { class DescribedBase {
public:
    virtual ~DescribedBase();
}; } }
typedef RBX::Reflection::DescribedBase Base;

namespace RBX { class DebrisService : public Reflection::DescribedBase {
}; }
typedef RBX::DebrisService Service;

namespace std {
    class bad_cast {
        void* table;
        const char* message;
        int ownsMessage;
    public:
        bad_cast(const char*);
        bad_cast(const bad_cast&);
        ~bad_cast();
    };
}

extern void (__thiscall *bad_cast_constructor)(std::bad_cast*, const char*);

inline std::bad_cast::bad_cast(const char* text)
{
    bad_cast_constructor(this, text);
}

typedef void (__thiscall *Callback)(void*, Shared, double);

struct S {
    char padding[56];
    Callback callback;
    int adjustment;
    Argument first;
    Argument second;

    void f(Base*, Arguments*);
};

void S::f(Base* object, Arguments* arguments)
{
    Argument a(first);
    arguments->get(1, a);

    Argument b(second);
    arguments->get(2, b);

    Service* service = dynamic_cast<Service*>(object);
    if (!service)
        throw std::bad_cast("bad cast");

    callback(reinterpret_cast<char*>(service) + adjustment,
             a.shared(), b.number());
}
