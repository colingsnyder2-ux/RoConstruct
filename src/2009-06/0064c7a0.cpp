// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct B0 { virtual ~B0(); int pad[4]; };
struct B1 { virtual void f1(); };
struct B2 { virtual void f2(); int pad; };
struct B3 { virtual void f3(); };
class GlobalSettings { public:
    class Item : public B0, public B1, public B2, public B3 { public: virtual ~Item(); };
};
extern const char* const sPhysicsSettings;
template<class T, class Base, const char* const* name>
class FactoryProduct : public Base {
public:
    virtual ~FactoryProduct() {}
};
template<class T, const char* const* name>
class __declspec(novtable) GlobalSettingsItem : public FactoryProduct<T, GlobalSettings::Item, name> {
public:
    static T* singleton;
    virtual ~GlobalSettingsItem() { singleton = 0; }
};
template<class T, const char* const* name> T* GlobalSettingsItem<T,name>::singleton;
class PhysicsSettings;
template class GlobalSettingsItem<PhysicsSettings, &sPhysicsSettings>;
}
