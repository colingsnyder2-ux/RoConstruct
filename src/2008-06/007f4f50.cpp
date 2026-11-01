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
    BoundProp(const char* name, const char* category, PropType (Class::*member),
              void (Class::*changed)(const PropertyDescriptor&), PropertyDescriptor::Functionality flags);
    ~BoundProp();
};
}

class Instance { public: virtual ~Instance(); };
class Listener { public: virtual ~Listener(); };

class ScriptContext : public Instance, public Listener
{
    char gap0[0x1a4];
    bool scriptsDisabled;
    void onScriptsDisabledChanged(const Reflection::PropertyDescriptor&);
public:
    static Reflection::BoundProp<bool, 1> prop_ScriptsDisabled;
};

Reflection::BoundProp<bool, 1> ScriptContext::prop_ScriptsDisabled("ScriptsDisabled", "State", &ScriptContext::scriptsDisabled, &ScriptContext::onScriptsDisabledChanged, (Reflection::PropertyDescriptor::Functionality)1);

}
