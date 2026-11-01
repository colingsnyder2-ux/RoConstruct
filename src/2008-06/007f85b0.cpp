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
class BrickColor { int number; };

class BrickColorValue : public Instance, public Listener
{
    char gap0[0x128];
    BrickColor value;
    void onValueChanged(const Reflection::PropertyDescriptor&);
public:
    static Reflection::BoundProp<BrickColor, 1> prop_Value;
};

Reflection::BoundProp<BrickColor, 1> BrickColorValue::prop_Value("Value", "Data", &BrickColorValue::value, &BrickColorValue::onValueChanged, (Reflection::PropertyDescriptor::Functionality)5);

}
