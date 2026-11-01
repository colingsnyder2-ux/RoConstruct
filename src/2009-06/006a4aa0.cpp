// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// 2009 Decal: DescribedBase at +0x18 (was +0x14 in 2008)
#include <string>

namespace RBX {

class DescribedBase { public: virtual ~DescribedBase(); };

class TextureId
{
    std::string name;
    int id;
};

class InstancePad { public: virtual ~InstancePad(); char pad[0x14]; };

class Decal : public InstancePad, public DescribedBase {};

namespace Reflection {

template<class Class, class T>
class PropDescriptor
{
public:
    class GetSet
    {
    public:
        virtual T getValue(const DescribedBase* object) const = 0;
        int reserved;
    };
    typedef const T (Class::*Getter)() const;
    typedef void (Class::*Setter)(T);
    class GetSetImpl : public GetSet
    {
    public:
        virtual T getValue(const DescribedBase* object) const
        {
            const Class* instance = static_cast<const Class*>(object);
            return (instance->*get)();
        }
        Getter get;
        Setter set;
    };
};

template class PropDescriptor<Decal, TextureId>::GetSetImpl;

}
}
