// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
enum SurfaceType { SMOOTH = 0 };
namespace Reflection { class DescribedBase { public: virtual ~DescribedBase(); }; }
class Surface;
class ExePad { public: virtual ~ExePad(); char pad[0x14]; };
class PartInstance : public ExePad, public Reflection::DescribedBase {
public:
    const Surface& getSurface() const;
};
class Surface { public: SurfaceType getType() const; };
template<class V>
class GetSet {
public:
    virtual V getValue(const Reflection::DescribedBase* p) const;
    V (Surface::*get)() const;
};
template<class V>
V GetSet<V>::getValue(const Reflection::DescribedBase* p) const
{
    const PartInstance* part = static_cast<const PartInstance*>(p);
    return (part->getSurface().*get)();
}
template class GetSet<SurfaceType>;
}
