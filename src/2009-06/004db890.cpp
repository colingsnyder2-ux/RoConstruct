// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
namespace G3D {
template<class T> class ReferenceCountedPointer {
public:
    T* m_pointer;
    ReferenceCountedPointer(const ReferenceCountedPointer& o);
    ~ReferenceCountedPointer();
};
}
namespace RBX { namespace Render {
class AggregatingSceneManager {
public:
    struct BucketKey {
        char data[0x150];
        bool operator<(const BucketKey& o) const;
    };
    class Bucket;
};
}}
typedef RBX::Render::AggregatingSceneManager ASM;
typedef std::_Tmap_traits<ASM::BucketKey, G3D::ReferenceCountedPointer<ASM::Bucket>, std::less<ASM::BucketKey>,
    std::allocator<std::pair<const ASM::BucketKey, G3D::ReferenceCountedPointer<ASM::Bucket> > >, false> Traits;
template std::_Tree<Traits>::_Tree(const std::less<ASM::BucketKey>&, const std::allocator<std::pair<const ASM::BucketKey, G3D::ReferenceCountedPointer<ASM::Bucket> > >&);
