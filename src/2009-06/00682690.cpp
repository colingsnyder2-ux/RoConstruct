// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
enum NormalId { NORM_X, NORM_Y, NORM_Z, NORM_X_NEG, NORM_Y_NEG, NORM_Z_NEG };
enum SurfaceType { NO_SURFACE };
namespace Reflection { class PropertyDescriptor; }
class Primitive {
    char pad[0xfc];
    SurfaceType surfaceType[6];
public:
    SurfaceType getSurfaceType(NormalId id) const { return surfaceType[id]; }
    void setSurfaceType(NormalId id, SurfaceType t);
};
class Surfaces {
public:
    const Reflection::PropertyDescriptor& getSurfaceType(NormalId id);
};
class PartInstance {
    char pad[0x118];
    Primitive* primitive;
public:
    Primitive* getPrimitive() const { return primitive; }
    void onSurfaceChanged(NormalId id);
    Surfaces& getSurfaces();
    void raisePropertyChanged(const Reflection::PropertyDescriptor&);
};
class Surface {
    PartInstance* partInstance;
    NormalId surfId;
public:
    SurfaceType getSurfaceType() const { return partInstance->getPrimitive()->getSurfaceType(surfId); }
    void setSurfaceType(SurfaceType type);
};
void Surface::setSurfaceType(SurfaceType type)
{
    if (type != getSurfaceType()) {
        partInstance->getPrimitive()->setSurfaceType(surfId, type);
        partInstance->onSurfaceChanged(surfId);
        PartInstance* p = partInstance;
        p->raisePropertyChanged(p->getSurfaces().getSurfaceType(surfId));
    }
}
}
