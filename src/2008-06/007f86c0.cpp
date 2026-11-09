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

class DoubleValue : public Instance, public Listener
{
    char gap0[0x128];
    double value;
    void onValueChanged(const Reflection::PropertyDescriptor&);
public:
    static Reflection::BoundProp<double, 1> prop_Value;
};

Reflection::BoundProp<double, 1> DoubleValue::prop_Value("Value", "Data", &DoubleValue::value, &DoubleValue::onValueChanged, (Reflection::PropertyDescriptor::Functionality)5);

}
