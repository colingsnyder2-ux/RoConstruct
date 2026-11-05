// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <vector>
namespace RBX {
struct B0 { virtual void f0(); char p[0x10]; };
struct B14 { virtual void f1(); };
struct B18 { virtual void f2(); void* descriptor; };
struct B20 { virtual void f3(); char p[0x68]; };
class Instance : public B0, public B14, public B18, public B20 {
public:
    Instance();
    ~Instance();
};
namespace GlobalSettings {
extern void* current;
class Item : public Instance {
public:
    char itemPad[0xd0 - 0x8c];
    virtual ~Item() {}
};
}
template<class Class, class DerivedClass, const char* const* ClassName>
class FactoryProduct : public DerivedClass {
public:
    virtual ~FactoryProduct() { GlobalSettings::current = 0; }
};
}
extern const char* const sRenderSettings;
class __declspec(novtable) CRenderSettingsItem : public RBX::FactoryProduct<CRenderSettingsItem, RBX::GlobalSettings::Item, &sRenderSettings> {
public:
    std::string name;
    int value;
    std::vector<int> items;
    ~CRenderSettingsItem();
};
CRenderSettingsItem::~CRenderSettingsItem() {}
