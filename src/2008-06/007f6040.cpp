// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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

class Skin : public Instance, public Listener
{
    char gap0[0x134 - 8];
    int outfit;
    void onOutfitChanged(const Reflection::PropertyDescriptor&);
public:
    static Reflection::BoundProp<int, 1> prop_Outfit1;
};

Reflection::BoundProp<int, 1> Skin::prop_Outfit1("Outfit1", "Appearance", &Skin::outfit, &Skin::onOutfitChanged, (Reflection::PropertyDescriptor::Functionality)0);

}
