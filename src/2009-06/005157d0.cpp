// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
namespace G3D { template<class T> class WeakReferenceCountedPointer { public:
    WeakReferenceCountedPointer(); WeakReferenceCountedPointer(const WeakReferenceCountedPointer& o); ~WeakReferenceCountedPointer();
    void* vp; void* p; }; }
namespace RBX {
namespace Render { class Material; }
namespace View { class MaterialFactory { public:
    struct Attributes { int a, b, c, d; bool operator<(const Attributes& o) const; };
}; }
}
typedef std::_Tmap_traits<RBX::View::MaterialFactory::Attributes, G3D::WeakReferenceCountedPointer<RBX::Render::Material>, std::less<RBX::View::MaterialFactory::Attributes>, std::allocator<std::pair<const RBX::View::MaterialFactory::Attributes, G3D::WeakReferenceCountedPointer<RBX::Render::Material> > >, false> Traits;
template class std::_Tree_nod<Traits>;
