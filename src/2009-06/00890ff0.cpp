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
class C_00890ff0 : public Instance, public Listener {
    char gap0[0x88];
    int value;
    void onChanged(const Reflection::PropertyDescriptor&);
public:
    static Reflection::BoundProp<int, 1> prop;
};
Reflection::BoundProp<int, 1> C_00890ff0::prop("Value", "Data", &C_00890ff0::value, &C_00890ff0::onChanged, (Reflection::PropertyDescriptor::Functionality)7);
}
