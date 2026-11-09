// Diagnostic profile adapted from src/2008-06/005f1690.cpp. Layout and globals provisional.
 #include "v8world/SurfaceData.h"
namespace RBX {
enum NormalId { NORM_X, NORM_Y, NORM_Z, NORM_X_NEG, NORM_Y_NEG, NORM_Z_NEG };
enum SurfaceType { SMOOTH };
namespace Reflection { class PropertyDescriptor {}; }
class Primitive {
    char padding[0xb8];
public:
    int values[1];
    void setSurfaceType(NormalId, SurfaceType);
};
class Surfaces { public: const Reflection::PropertyDescriptor& getSurfaceType(NormalId) const; };
class Instance { public: void raisePropertyChanged(const Reflection::PropertyDescriptor&); };
class PartInstance : public Instance {
    char padding[0x228];
public:
    Primitive primitive;
    void onSurfaceChanged(NormalId);
    Surfaces& getSurfaces();
};
class Surface {
    PartInstance* part;
    NormalId face;
public:
    void setSurfaceInput(Controller::InputType);
    void setParamA(float);
    void setParamB(float);
    void flat();
};
void Surface::flat() {
    if (part->primitive.values[face] != 0) {
        part->primitive.setSurfaceType(face, SMOOTH);
        part->onSurfaceChanged(face);
        part->raisePropertyChanged(part->getSurfaces().getSurfaceType(face));
    }
    setSurfaceInput(SurfaceData::empty().inputType);
    setParamA(SurfaceData::empty().paramA);
    setParamB(SurfaceData::empty().paramB);
}
}
