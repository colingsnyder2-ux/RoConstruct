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

class Rocket : public Instance, public Listener
{
    char gap0[0x158];
    float targetRadius;
    void onGoalChanged(const Reflection::PropertyDescriptor&);
public:
    static Reflection::BoundProp<float, 1> prop_TargetRadius;
};

Reflection::BoundProp<float, 1> Rocket::prop_TargetRadius("TargetRadius", "Goals", &Rocket::targetRadius, &Rocket::onGoalChanged, (Reflection::PropertyDescriptor::Functionality)5);

}
