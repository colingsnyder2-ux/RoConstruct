// from server: 100% by EspClaude
// roc 2007-08 005ef1e0  BoundFuncDesc<BodyVelocity, Vector3>::execute: polymorphic_cast + call bound const getter (MI member pointer), store result
#include <typeinfo>

namespace RBX {
namespace Reflection {
class DescribedBase { public:
    virtual ~DescribedBase();
};
}
class SecondBase { public:
    virtual ~SecondBase();
};
}

namespace boost {
template <class Target, class Source>
inline Target polymorphic_cast(Source* x)
{
    Target tmp = dynamic_cast<Target>(x);
    if (tmp == 0) throw std::bad_cast();
    return tmp;
}
}

struct Vector3 {
    float x, y, z;
    Vector3() {}
};

namespace RBX {
class BodyVelocity : public Reflection::DescribedBase, public SecondBase {
};
}

struct ReturnValue {
    ReturnValue& operator=(const Vector3&);
};

struct Arguments {
    int header;
    ReturnValue returnValue;
};

struct BoundFuncDesc {
    char padding[0x28];
    Vector3 (RBX::BodyVelocity::*function)() const;

    void execute(RBX::Reflection::DescribedBase*, Arguments&);
};

void BoundFuncDesc::execute(RBX::Reflection::DescribedBase* source, Arguments& arguments)
{
    arguments.returnValue = (boost::polymorphic_cast<RBX::BodyVelocity*>(source)->*function)();
}
