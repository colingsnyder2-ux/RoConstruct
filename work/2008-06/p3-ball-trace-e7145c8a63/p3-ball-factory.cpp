// Implementation: C:\Users\colin\RoConstruct\tools\rbxgs\Client\App\roc_espclaude_55da838f8acf90fb.cpp
// Build pointer preserved: C:\Users\colin\RoConstruct\src\2008-06\004eea30.cpp
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
    char pad[0x8c - sizeof(Render::Mesh)];
};

template<class Mesh, size_t numMeshes>
class MeshFactory
{
public:
    struct Variations
    {
        G3D::ReferenceCountedPointer<Render::Mesh> meshes[numMeshes];
    };
    struct Cache
    {
        G3D::Table<RenderSurfaceTypes, G3D::Table<G3D::Vector3, Variations> > cache1;
        boost::recursive_mutex mutex;
        std::map<int, int> decalCache;
        std::map<int, int> textureCache;
        int count;
    };
    static Cache* cache;
    static boost::once_flag cacheOnce;
    static void initCache();
    static Mesh* create(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes);
};

template<class Mesh, size_t numMeshes>
Mesh* MeshFactory<Mesh, numMeshes>::create(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes)
{
    boost::call_once(initCache, cacheOnce);
    Cache* c = cache;
    boost::recursive_mutex::scoped_lock lock(c->mutex);

    if (!c->cache1.containsKey(surfaceTypes))
        c->cache1.set(surfaceTypes, G3D::Table<G3D::Vector3, Variations>());

    G3D::Table<G3D::Vector3, Variations>& sizeCache = c->cache1.get(surfaceTypes);

    if (!sizeCache.containsKey(size))
        sizeCache.set(size, Variations());

    Variations& variation = sizeCache.get(size);

    Mesh* mesh = static_cast<Mesh*>(variation.meshes[0].getPointer());
    if (!mesh)
    {
        mesh = new Mesh(size, surfaceTypes);
        variation.meshes[0] = mesh;
        if (++c->count % 100 == 0)
        {
            G3D::ReferenceCountedPointer<Render::Mesh> keep = variation.meshes[0];
            flushUnusedMeshCache();
        }
    }
    return mesh;
}

template class MeshFactory<SphereMesh, 1>;
}
}
