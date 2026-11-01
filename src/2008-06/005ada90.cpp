// from server: 100% by colin
#include <typeinfo>
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Control
{
    virtual ~Control();
    virtual void unused();
    virtual Control *clone();

    static Control *copy(Control *);
};

inline Control *Control::copy(Control *p)
{
    if (p)
        return p->clone();
    return 0;
}

struct Value
{
    void *data;
    Control *control;

    Value(void *, Control *);
    ~Value();
    const double *number();
};

inline Value::Value(void *p, Control *c)
    : data(p), control(Control::copy(c))
{
}

inline Value::~Value()
{
    if (control)
        delete control;
}

struct Arguments
{
    virtual void unused();
    virtual void get(int, Value *);
};

namespace RBX { namespace Reflection { class DescribedBase { public: virtual ~DescribedBase(); }; } }
using RBX::Reflection::DescribedBase;

namespace RBX { class ScriptContext : public DescribedBase {}; }
using RBX::ScriptContext;



struct S
{
    char padding[0x38];
    void (__thiscall *callback)(void *, double);
    int adjustment;
    void *data;
    Control *control;

    void f(DescribedBase *, Arguments *);
};

void S::f(DescribedBase *object, Arguments *arguments)
{
    Value value(data, control);
    arguments->get(1, &value);

    ScriptContext *context = dynamic_cast<ScriptContext *>(object);
    if (!context)
        throw std::bad_cast("bad cast");

    callback(reinterpret_cast<char *>(context) + adjustment, *value.number());
}
