// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
template<class T> class SharedRef { public: T* px; void* pn; SharedRef() : px(0), pn(0) {} ~SharedRef(); };
struct B0 { virtual ~B0(); char pad[0x10]; };
struct B1 { virtual ~B1(); };
struct B2 { virtual ~B2(); int x; };
struct B3 { virtual ~B3(); char pad[0xac]; };
class Instance : public B0, public B1, public B2, public B3 {
public:
    void setName(const std::string& name);
};
class SettingsBase : public Instance {
public:
    SettingsBase();
    virtual ~SettingsBase();
};
class Item;
class GlobalSettings : public SettingsBase {
public:
    GlobalSettings();
    virtual ~GlobalSettings();
    SharedRef<Item> item;
};
GlobalSettings::GlobalSettings()
{
    setName("Global Settings");
}
}
