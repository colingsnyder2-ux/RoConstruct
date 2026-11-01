// from server: 100% by tester
#include <typeinfo>
namespace RBX { namespace Reflection { class DescribedBase { public: virtual ~DescribedBase(); }; } }
namespace RBX { class Teams : public RBX::Reflection::DescribedBase { }; }
struct Arg { int header; int member; };
struct Holder {
    void apply(RBX::Teams* object, int* value);
    void invoke(RBX::Reflection::DescribedBase* source, Arg* arg);
};

void Holder::invoke(RBX::Reflection::DescribedBase* source, Arg* arg)
{
    RBX::Teams* object = dynamic_cast<RBX::Teams*>(source);
    if (!object)
        throw std::bad_cast("bad cast");
    apply(object, &arg->member);
}
