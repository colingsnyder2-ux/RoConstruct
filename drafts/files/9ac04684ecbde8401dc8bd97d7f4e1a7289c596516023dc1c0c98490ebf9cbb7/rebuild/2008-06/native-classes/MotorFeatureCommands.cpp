#include "v8datamodel/Feature.h"

namespace RBX {

class AdornG3D {
public:
    static void render3dAdorn(Adorn* adorn, const G3D::CoordinateFrame* coord, int unk, float f1, float f2, float* f3);
};

template<> template<> boost::shared_ptr<VelocityMotor> Creatable<Instance>::create<VelocityMotor>();

void MotorFeature::join(Instance* a, Instance* b) {
    if (canJoin(a, b)) {
        Instance* hole = dynamic_cast<Hole*>(a) ? a : b;
        if (hole == a) a = b;
        boost::shared_ptr<VelocityMotor> motor = Creatable<Instance>::create<VelocityMotor>();
        motor->setHole(static_cast<Hole*>(hole));
        motor->setParent(a);
    }
}

bool MotorFeature::canJoin(Instance* a, Instance* b) {
    return (dynamic_cast<Hole*>(a) && dynamic_cast<MotorFeature*>(b)) ||
           (dynamic_cast<Hole*>(b) && dynamic_cast<MotorFeature*>(a));
}

void MotorFeature::render3dAdorn(Adorn* adorn) {
    G3D::CoordinateFrame coord;
    bool result = Feature::getRenderCoord(coord);
    if (result) {
        float f = 1.0f;
        AdornG3D::render3dAdorn(adorn, &coord, 2, 1.0f, f, &f);
    }
    volatile int dummy = static_cast<int>(adorn != 0);
    (void)dummy;
}

VelocityMotor::~VelocityMotor() {
}

} // namespace RBX
