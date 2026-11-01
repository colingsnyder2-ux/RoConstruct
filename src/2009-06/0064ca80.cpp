// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class PropertyDescriptor { int x[8]; }; }
namespace EThrottle { enum EThrottleType { ThrottleDisabled }; extern EThrottleType globalDebugEThrottle; }
extern bool throttleFlag;
extern Reflection::PropertyDescriptor prop_enviromentalThrottle;
inline EThrottle::EThrottleType filter(EThrottle::EThrottleType v) { if (!throttleFlag) return EThrottle::ThrottleDisabled; return v; }
class Instance { public: void raisePropertyChanged(const Reflection::PropertyDescriptor& d); };
class PhysicsSettings : public Instance {
public:
    EThrottle::EThrottleType getEThrottle() const { return EThrottle::globalDebugEThrottle; }
    void setEThrottle(EThrottle::EThrottleType value);
};
void PhysicsSettings::setEThrottle(EThrottle::EThrottleType value)
{
    if (!throttleFlag) value = EThrottle::ThrottleDisabled;
    EThrottle::EThrottleType v = value;
    if (v != getEThrottle()) {
        EThrottle::globalDebugEThrottle = v;
        raisePropertyChanged(prop_enviromentalThrottle);
    }
}
}
