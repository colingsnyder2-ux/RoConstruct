// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <map>
namespace G3D {
template<class T> class ReferenceCountedPointer {
public:
    ReferenceCountedPointer(const ReferenceCountedPointer&);
    ~ReferenceCountedPointer();
    T* m_pointer;
};
}
namespace RBX { namespace Render {
class Material;
class AggregatingSceneManager {
public:
    class Bucket;
    struct BucketKey {
        int material;
        float polygonOffset;
        float polygonOffset2;
        int cullable;
        G3D::ReferenceCountedPointer<Material> mat;
        bool operator<(const BucketKey&) const;
    };
    typedef std::map<BucketKey, G3D::ReferenceCountedPointer<Bucket> > Map;
};
bool AggregatingSceneManager::BucketKey::operator<(const AggregatingSceneManager::BucketKey& that) const
{
    if (this->material < that.material)
        return true;
    if (this->material > that.material)
        return false;
    if (this->polygonOffset < that.polygonOffset)
        return true;
    if (this->polygonOffset > that.polygonOffset)
        return false;
    if (this->polygonOffset2 < that.polygonOffset2)
        return true;
    if (this->polygonOffset2 > that.polygonOffset2)
        return false;
    if (this->cullable < that.cullable)
        return true;
    else
        return false;
}
}}
template std::pair<RBX::Render::AggregatingSceneManager::Map::iterator, bool>
std::_Tree<std::_Tmap_traits<RBX::Render::AggregatingSceneManager::BucketKey, G3D::ReferenceCountedPointer<RBX::Render::AggregatingSceneManager::Bucket>, std::less<RBX::Render::AggregatingSceneManager::BucketKey>, std::allocator<std::pair<const RBX::Render::AggregatingSceneManager::BucketKey, G3D::ReferenceCountedPointer<RBX::Render::AggregatingSceneManager::Bucket> > >, false> >::insert(const value_type&);
