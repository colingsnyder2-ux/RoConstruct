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

class BodyColors : public Instance, public Listener
{
    char gap0[0x13c];
    BrickColor leftLegColor;
    void onColorChanged(const Reflection::PropertyDescriptor&);
public:
    static Reflection::BoundProp<BrickColor, 1> prop_LeftLegColor;
};

Reflection::BoundProp<BrickColor, 1> BodyColors::prop_LeftLegColor("LeftLegColor", "Appearance", &BodyColors::leftLegColor, &BodyColors::onColorChanged, (Reflection::PropertyDescriptor::Functionality)5);

}
