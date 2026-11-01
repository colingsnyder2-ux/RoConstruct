// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace G3D {
inline float clamp(float val, float low, float hi) {
    if (val <= low) return low; else if (val >= hi) return hi; else return val;
}
}
namespace RBX {
namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); char pad[0x10]; };
class PropertyDescriptor {
public:
    virtual ~PropertyDescriptor();
    virtual void a();
    virtual void b();
    virtual void setValue(DescribedBase* instance, const float& value) const;
};
}
class ExePad { public: virtual ~ExePad(); char pad[0x14]; };
class Sound : public ExePad, public Reflection::DescribedBase {
public:
    char pad2[0xcc - 0x2c];
    float volume;
    void setVolume(float value);
};
extern const Reflection::PropertyDescriptor* prop_Volume;
void Sound::setVolume(float value)
{
    value = G3D::clamp(value, 10.0f, 250.0f);
    if (value != volume)
        prop_Volume->setValue(this, value);
}
}
