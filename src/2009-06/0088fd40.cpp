// from server: 100% by EspClaude
// roc 2009-06 0088fd40
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
class Instance : public virtual VBase { public: virtual ~Instance(); float getMaxHealth() const; void setMaxHealth(float); };
class Pad { public: virtual ~Pad(); char pad[0x13c - 4]; };
class Humanoid : public Pad, public Instance
{
public:
    float getMaxHealth() const;
    void setMaxHealth(float);
};
static Reflection::PropDescriptor<Instance, float> desc_MaxHealth("MaxHealth", "Game", static_cast<float (Instance::*)() const>(&Humanoid::getMaxHealth), static_cast<void (Instance::*)(float)>(&Humanoid::setMaxHealth), 7);
}
