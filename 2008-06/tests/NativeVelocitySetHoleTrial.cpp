#include "v8tree/Instance.h"
#include <boost/bind.hpp>
#include <boost/signals.hpp>
namespace RBX {
class Feature : public Instance {};
class Hole : public Feature {};
class VelocityMotor;
extern Reflection::RefPropDescriptor<VelocityMotor, Hole> prop_Hole;
class VelocityMotor : public Instance {
    char diagnosticPrefix[0x24];
    boost::shared_ptr<Hole> hole;
    boost::signals::scoped_connection holeAncestorChanged;
    void setPart(int, Feature*);
    void onEvent_HoleAncestorChanged();
public:
    Hole* getHole() const { return hole.get(); }
    void setHole(Hole*);
};
void VelocityMotor::setHole(Hole* value) {
    if (value != getHole()) {
        hole = RBX::shared_from(value);
        raisePropertyChanged(prop_Hole);
        setPart(1, getHole());
        if (getHole())
            holeAncestorChanged = event_ancestryChanged.connect(hole.get(), boost::bind(&VelocityMotor::onEvent_HoleAncestorChanged, this), 10);
        else
            holeAncestorChanged.disconnect();
    }
}
}
