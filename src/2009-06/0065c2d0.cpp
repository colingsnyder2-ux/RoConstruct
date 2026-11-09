// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
enum NormalId { NORM_X = 0, NORM_UNDEFINED = 6 };
enum SurfaceType { FLAT, GLUE, WELD, STUDS, INLET, UNIVERSAL, ROTATE, ROTATE_P, ROTATE_V };
class Surface {
public:
    SurfaceType getSurfaceType() const;
};
class Surfaces {
public:
    const Surface& operator[](NormalId id) const;
};
class PartInstance {
public:
    char pad[0x134];
    Surfaces surfaces;
    bool computeSurfacesNeedAdorn() const;
};
bool PartInstance::computeSurfacesNeedAdorn() const
{
    for (int i = 0; i < 6; ++i) {
        const Surface& s = surfaces[(NormalId)i];
        if (s.getSurfaceType() == ROTATE || s.getSurfaceType() == ROTATE_V || s.getSurfaceType() == ROTATE_P)
            return true;
    }
    return false;
}
}
