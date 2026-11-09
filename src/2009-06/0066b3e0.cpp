// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <math.h>
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    float unitize(float tolerance);
};
class Vector2 {
public:
    float x, y;
    Vector2(float a, float b) : x(a), y(b) {}
};
class CoordinateFrame {
public:
    Vector3 lookVector() const;
};
}
using namespace G3D;
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
class PartInstance {
public:
    const CoordinateFrame& getCoordinateFrame() const;
};
extern Reflection::PropertyDescriptor prop_angle;
float __cdecl directionAngle(const Vector2&);
float __cdecl wrapAngle(double);
class Humanoid {
public:
    char pad[0x1d4];
    float angle;
    PartInstance* getTorso();
    void raisePropertyChanged(const Reflection::PropertyDescriptor&);
};
class HumanoidController {
public:
    void update(float desiredAngle, bool reset);
};
void HumanoidController::update(float desiredAngle, bool reset)
{
    if (reset) {
        Humanoid* owner = reinterpret_cast<Humanoid*>(reinterpret_cast<char*>(this) - 0x13c);
        if (owner->angle != 0.0f) {
            owner->angle = 0.0f;
            owner->raisePropertyChanged(prop_angle);
        }
        return;
    }
    Humanoid* owner = reinterpret_cast<Humanoid*>(reinterpret_cast<char*>(this) - 0x13c);
    if (PartInstance* torso = owner->getTorso()) {
        Vector3 look = torso->getCoordinateFrame().lookVector();
        look.y = 0.0f;
        look.unitize(0.000001f);
        Vector2 planar(look.z, look.x);
        float desired = wrapAngle(desiredAngle);
        float current = wrapAngle(directionAngle(planar));
        float difference = wrapAngle(desired - current);
        if (fabs(difference) < 0.1f)
            difference = 0.0f;
        if (owner->angle != difference) {
            owner->angle = difference;
            owner->raisePropertyChanged(prop_angle);
        }
    }
}
}
