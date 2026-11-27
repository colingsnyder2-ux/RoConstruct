// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern bool gFlag;
namespace RBX {
class Instance { public: virtual ~Instance(); };
class GlobalBasicSettings { public: class Item : public Instance { public: virtual void a(); }; };
class GlobalAdvancedSettings { public: class Item : public Instance { public: virtual void b(); }; };
class Selection : public Instance { public: virtual void c(); };
}
int f(RBX::Instance* p) {
    if (gFlag && !dynamic_cast<RBX::GlobalBasicSettings::Item*>(p) && !dynamic_cast<RBX::GlobalAdvancedSettings::Item*>(p) && !dynamic_cast<RBX::Selection*>(p)) return 1;
    return 0;
}