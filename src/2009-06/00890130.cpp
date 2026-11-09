// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection {
class PropertyDescriptor
{
public:
    enum Functionality { STANDARD = 7 };
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
    char gap0[0x244];
    int forcefieldDuration;
public:
    static Reflection::BoundProp<int, 1> prop_Duration;
};

Reflection::BoundProp<int, 1> SpawnLocation::prop_Duration("Duration", "Forcefield", &SpawnLocation::forcefieldDuration, Reflection::PropertyDescriptor::STANDARD);
}
