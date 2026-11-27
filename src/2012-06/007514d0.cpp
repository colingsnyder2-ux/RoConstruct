// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
enum NormalId { NORM_X, NORM_Y, NORM_Z, NORM_X_NEG, NORM_Y_NEG, NORM_Z_NEG };
enum SurfaceType { ROTATE = 6, ROTATE_P = 7, ROTATE_V = 8 };
struct Surface { SurfaceType getSurfaceType() const; };
struct Surfaces { Surface& operator[](NormalId id) const; };
struct PartInstance {
    char pad[0x1b4];
    Surfaces surfaces;
    bool computeSurfacesNeedAdorn() const;
};
bool PartInstance::computeSurfacesNeedAdorn() const
{
    for (int i = 0; i < 6; i++)
    {
        Surface& current = surfaces[(NormalId)i];
        if (current.getSurfaceType() == ROTATE || current.getSurfaceType() == ROTATE_V || current.getSurfaceType() == ROTATE_P)
            return true;
    }
    return false;
}
}
