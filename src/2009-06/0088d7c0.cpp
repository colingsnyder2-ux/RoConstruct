// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection {
class PropertyDescriptor { public: enum Functionality { STANDARD = 7 }; };
template<typename PropType, int Unknown>
class BoundProp {
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
class C_0088d7c0 : public Instance, public Listener {
    char gap0[0xac];
    float value;
    void onChanged(const Reflection::PropertyDescriptor&);
public:
    static Reflection::BoundProp<float, 1> prop;
};
Reflection::BoundProp<float, 1> C_0088d7c0::prop("DopplerScale", "Data", &C_0088d7c0::value, &C_0088d7c0::onChanged, (Reflection::PropertyDescriptor::Functionality)7);
}
