// from server: 100% by tester
namespace RBX {
namespace Reflection {
class PropertyDescriptor
{
public:
    enum Functionality { STANDARD = 5 };
};

template<typename PropType, int Unknown>
class BoundProp
{
    char data[0x40];
public:
    template<typename Class>
    BoundProp(const char* name, const char* category, PropType (Class::*member), PropertyDescriptor::Functionality flags);
    ~BoundProp();
};
}

class Instance { public: virtual ~Instance(); };

class Tool : public virtual Instance
{
    char gap0[0x1f8];
    bool enabled;
public:
    static Reflection::BoundProp<bool, 1> prop_Enabled;
};

Reflection::BoundProp<bool, 1> Tool::prop_Enabled("Enabled", "State", &Tool::enabled, Reflection::PropertyDescriptor::STANDARD);
}
