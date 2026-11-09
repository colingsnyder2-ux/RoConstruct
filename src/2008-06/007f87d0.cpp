// from server: 100% by tester
namespace G3D { class Color3 { public: float r, g, b; }; }
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

class Color3Value : public Instance, public Listener
{
    char gap0[0x128];
    G3D::Color3 value;
    void onValueChanged(const Reflection::PropertyDescriptor&);
public:
    static Reflection::BoundProp<G3D::Color3, 1> prop_Value;
};

Reflection::BoundProp<G3D::Color3, 1> Color3Value::prop_Value("Value", "Data", &Color3Value::value, &Color3Value::onValueChanged, (Reflection::PropertyDescriptor::Functionality)5);

}
