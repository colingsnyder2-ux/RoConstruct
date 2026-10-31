// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <typeinfo>
namespace RBX {
namespace Reflection { class DescribedBase { public: virtual ~DescribedBase(); }; }
class InstanceBase { char d[0x14]; public: virtual ~InstanceBase(); };
class Instance : public InstanceBase, public Reflection::DescribedBase {};
class Hole : public Instance {};
}
namespace boost {
template <class Target, class Source>
inline Target polymorphic_cast(Source* x)
{
    Target tmp = dynamic_cast<Target>(x);
    if ( tmp == 0 ) throw std::bad_cast();
    return tmp;
}
}
template RBX::Hole* boost::polymorphic_cast<RBX::Hole*, RBX::Reflection::DescribedBase>(RBX::Reflection::DescribedBase*);
