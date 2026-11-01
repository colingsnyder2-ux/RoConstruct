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

class SpawnLocation : public virtual Instance
{
    char gap0[0x3fd];
    bool allowTeamChangeOnTouch;
public:
    static Reflection::BoundProp<bool, 1> prop_AllowTeamChangeOnTouch;
};

Reflection::BoundProp<bool, 1> SpawnLocation::prop_AllowTeamChangeOnTouch("AllowTeamChangeOnTouch", "Teams", &SpawnLocation::allowTeamChangeOnTouch, Reflection::PropertyDescriptor::STANDARD);
}
