// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
namespace G3D { template<class T> class ReferenceCountedPointer { public: T* p; ReferenceCountedPointer() : p(0) {} ~ReferenceCountedPointer(); }; }
namespace RBX { namespace Render { class AggregatingSceneManager { public:
    struct BucketKey { double d; char data[0x140]; bool operator<(const BucketKey& o) const; };
    class Bucket;
    typedef std::map<BucketKey, G3D::ReferenceCountedPointer<Bucket> > Buckets;
}; } }
class Exposer : public RBX::Render::AggregatingSceneManager::Buckets { public: _Nodeptr buy() { return _Buynode(); } };
template class std::_Tree<std::_Tmap_traits<RBX::Render::AggregatingSceneManager::BucketKey, G3D::ReferenceCountedPointer<RBX::Render::AggregatingSceneManager::Bucket>, std::less<RBX::Render::AggregatingSceneManager::BucketKey>, std::allocator<std::pair<const RBX::Render::AggregatingSceneManager::BucketKey, G3D::ReferenceCountedPointer<RBX::Render::AggregatingSceneManager::Bucket> > >, false> >;
