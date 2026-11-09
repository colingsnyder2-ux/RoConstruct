// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_decalcachepointerorderb8662ca4108cc8fa.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <G3D/Vector3.h>
#include <G3D/ReferenceCount.h>
namespace RBX {
enum NormalId { NORM_X };
namespace Render { class Mesh : public G3D::ReferenceCountedObject {}; }
namespace View {
class PBBMesh;
template <class T, int N>
class MeshFactory
{
public:
    class DecalKey
    {
    private:
        G3D::Vector3 size; // 0x00
        NormalId face;     // 0x0c
    public:
        bool operator<(const DecalKey& other) const
        {
            if (face < other.face)
                return true;
            if (face > other.face)
                return false;
            return static_cast<const float*>(size) < static_cast<const float*>(other.size);
        }
    };
    typedef std::map<DecalKey, G3D::ReferenceCountedPointer<Render::Mesh> > DecalCache;
    static DecalCache decalCache;
    static G3D::ReferenceCountedPointer<Render::Mesh>& get(const DecalKey& key) { return decalCache[key]; }
};
template class MeshFactory<PBBMesh, 4>;
}
}
