// from server: 100% by EspClaude
// roc 2007-08 005f6440  Value<bool>::Value() : value(ValueType()) { setName("Value"); }
// Instance-derived layout from the target: polymorphic subobjects at 0,4,0x10,0x14,0x2c,0x44,0x5c,0x74,0x8c;
// value @0xe8. Base constructor and Instance::setName(const std::string&) are out of line.
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace RBX {
class V0 { public: virtual ~V0(); };
class V1 { public: virtual ~V1(); int a, b; };
class V2 { public: virtual ~V2(); };
template<int N> class Notifier { public: virtual ~Notifier(); int pad[5]; };
class V8 { public: virtual ~V8(); char pad[0xe8 - 0x90]; };
class ValueBase : public V0, public V1, public V2, public Notifier<1>, public Notifier<2>, public Notifier<3>,
                  public Notifier<4>, public Notifier<5>, public V8 {
public:
    ValueBase();
    void setName(const std::string& name);
};
template<typename ValueType>
class Value : public ValueBase {
public:
    ValueType value;
    Value() : value(ValueType()) { this->setName("Value"); }
};
template class Value<bool>;
}
