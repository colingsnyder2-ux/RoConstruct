// >>> native-status (generated) -- do not edit >>>
// MotorFeatureCommands | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 9c66d060 | roc native-status --write
#include "v8datamodel/Feature.h"
namespace RBX {
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
}
