// from server: 100% by tester
namespace G3D { class Vector3 { public: float x, y, z; }; }
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
    char gap0[0x14c];
    G3D::Vector3 targetOffset;
    void onGoalChanged(const Reflection::PropertyDescriptor&);
public:
    static Reflection::BoundProp<G3D::Vector3, 1> prop_TargetOffset;
};

Reflection::BoundProp<G3D::Vector3, 1> Rocket::prop_TargetOffset("TargetOffset", "Goals", &Rocket::targetOffset, &Rocket::onGoalChanged, (Reflection::PropertyDescriptor::Functionality)5);

}
