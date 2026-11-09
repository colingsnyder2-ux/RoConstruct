// from server: 100% by EspClaude
// roc 2009-06 0088fc20
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection {
template<class C, class V>
class PropDescriptor {
public:
    template<class Getter, class Setter>
    PropDescriptor(const char* name, const char* category, Getter getter, Setter setter, int f);
    ~PropDescriptor();
private:
    char data[0x50];
};
}
class VBase { public: virtual ~VBase(); };
class Instance : public virtual VBase { public: virtual ~Instance(); bool getSit() const; void setSit(bool); };
class Pad { public: virtual ~Pad(); char pad[0x13c - 4]; };
class Humanoid : public Pad, public Instance
{
public:
    bool getSit() const;
    void setSit(bool);
};
static Reflection::PropDescriptor<Instance, bool> desc_Sit("Sit", "Control", static_cast<bool (Instance::*)() const>(&Humanoid::getSit), static_cast<void (Instance::*)(bool)>(&Humanoid::setSit), 2);
}
