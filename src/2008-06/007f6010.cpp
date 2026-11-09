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

class ShirtGraphic : public Instance, public Listener
{
    char gap0[0x12c];
    int graphic;
    void onGraphicChanged(const Reflection::PropertyDescriptor&);
public:
    static Reflection::BoundProp<int, 1> prop_Graphic;
};

Reflection::BoundProp<int, 1> ShirtGraphic::prop_Graphic("Graphic", "Appearance", &ShirtGraphic::graphic, &ShirtGraphic::onGraphicChanged, (Reflection::PropertyDescriptor::Functionality)5);

}
