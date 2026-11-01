// from server: 100% by tester
#include <typeinfo>

namespace RBX {
namespace Reflection {
class DescribedBase
{
public:
    virtual ~DescribedBase();
};

class FunctionDescriptor
{
public:
    class Arguments;
    virtual void execute(DescribedBase* object, Arguments& arguments) const = 0;
};

template<class Class, typename Function, int Unknown>
class BoundFuncDesc : public FunctionDescriptor
{
    char data[0x34];
    void (Class::*function)();
public:
    virtual void execute(DescribedBase* object, Arguments& arguments) const
    {
        Class* o = dynamic_cast<Class*>(object);
        if (!o)
            throw std::bad_cast();
        (o->*function)();
    }
};
}

class Notifier { public: virtual ~Notifier(); };

class PVInstance : public Notifier, public Reflection::DescribedBase
{
    char data[0x12c];
};

class IModelModifier { public: virtual ~IModelModifier(); };

class ModelInstance : public PVInstance, public virtual IModelModifier
{
};

template class Reflection::BoundFuncDesc<ModelInstance, void(), 0>;
}
