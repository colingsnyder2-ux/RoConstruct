// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_ad093b80fd4773c5.cpp

// Candidate translation unit (score above; library headers required).
#include <RenderLib/Mesh.h>
#include <util/NormalId.h>

namespace RBX { namespace View {
class RenderSurfaceTypes
{
public:
    size_t data;
    RenderSurfaceTypes() : data(0) {}
    unsigned int hashCode() const { return data; }
    bool operator==(const RenderSurfaceTypes& other) const { return data == other.data; }
};
}}
inline unsigned int hashCode(const RBX::View::RenderSurfaceTypes& t) { return t.hashCode(); }

#include <G3D/Table.h>
#include <boost/thread/recursive_mutex.hpp>
#include <boost/thread/once.hpp>
#include <map>

void flushUnusedMeshCache();
namespace RBX {
namespace View {

class SphereMesh : public Render::Mesh
{
public:
    SphereMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes);
};

template<class Mesh, size_t numMeshes>
class MeshFactory
{
public:
    class DecalKey
    {
    private:
        G3D::Vector3 size;
        NormalId face;
    public:
        bool operator<(const DecalKey&) const;
    };
    class TextureKey : protected DecalKey
    {
    private:
        G3D::Vector2 studsPerTile;
    public:
        bool operator<(const TextureKey&) const;
    };
    struct Variations
    {
        G3D::ReferenceCountedPointer<Render::Mesh> meshes[numMeshes];
    };
    struct Cache
    {
        G3D::Table<RenderSurfaceTypes, G3D::Table<G3D::Vector3, Variations> > cache1;
        boost::recursive_mutex mutex;
        std::map<DecalKey, G3D::ReferenceCountedPointer<Render::Mesh> > decalCache;
        std::map<TextureKey, G3D::ReferenceCountedPointer<Render::Mesh> > textureCache;
        int count;
    };
    static Cache* cache;
    static boost::once_flag cacheOnce;
    static void initCache();
    static void flushUnused();
};

template<class Mesh, size_t numMeshes>
void MeshFactory<Mesh, numMeshes>::flushUnused()
{
    boost::call_once(initCache, cacheOnce);
    Cache* c = cache;
    boost::recursive_mutex::scoped_lock lock(c->mutex);

    for (typename G3D::Table<RenderSurfaceTypes, G3D::Table<G3D::Vector3, Variations> >::Iterator it = c->cache1.begin(); it != c->cache1.end(); it++)
    {
        G3D::Table<G3D::Vector3, Variations>& sizeCache = it->value;
        for (typename G3D::Table<G3D::Vector3, Variations>::Iterator it2 = sizeCache.begin(); it2 != sizeCache.end(); it2++)
        {
            for (size_t i = 0; i < numMeshes; ++i)
            {
                if (it2->value.meshes[i].notNull() && it2->value.meshes[i].isLastReference())
                    it2->value.meshes[i] = NULL;
            }
        }
    }

    for (typename std::map<DecalKey, G3D::ReferenceCountedPointer<Render::Mesh> >::iterator it = c->decalCache.begin(); it != c->decalCache.end(); ++it)
    {
        if (it->second.notNull() && it->second.isLastReference())
            it->second = NULL;
    }

    for (typename std::map<TextureKey, G3D::ReferenceCountedPointer<Render::Mesh> >::iterator it = c->textureCache.begin(); it != c->textureCache.end(); ++it)
    {
        if (it->second.notNull() && it->second.isLastReference())
            it->second = NULL;
    }
}

template class MeshFactory<SphereMesh, 4>;
}
}
