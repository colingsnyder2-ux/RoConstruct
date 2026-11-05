// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
enum SurfaceType { SMOOTH = 0 };
enum NormalId { NORM_X = 0, NORM_Y, NORM_Z, NORM_X_NEG, NORM_Y_NEG, NORM_Z_NEG };
namespace Reflection { class DescribedBase { public: virtual ~DescribedBase(); }; }
class Surface { int data[2]; public: SurfaceType getType() const; };
class Surfaces {
    Surface surfaces[6];
public:
    const Surface& operator[](NormalId id) const { return surfaces[id]; }
};
class ExePad { public: virtual ~ExePad(); char pad[0x14]; };
class PartInstance : public ExePad, public Reflection::DescribedBase {
public:
    const Surfaces& getSurfaces() const;
};
template<NormalId face>
class SurfaceGetSet {
public:
    virtual SurfaceType getValue(const Reflection::DescribedBase* p) const;
    SurfaceType (Surface::*get)() const;
};
template<NormalId face>
SurfaceType SurfaceGetSet<face>::getValue(const Reflection::DescribedBase* p) const
{
    const PartInstance* part = static_cast<const PartInstance*>(p);
    return (part->getSurfaces()[face].*get)();
}
template class SurfaceGetSet<NORM_X_NEG>;
}
