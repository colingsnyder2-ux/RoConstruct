// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_38534945e3384860.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector3.h>
#include <G3D/ReferenceCount.h>
#include <G3D/g3dmath.h>
#include <boost/thread/recursive_mutex.hpp>
#include <boost/thread/once.hpp>
#include <map>
#include <algorithm>

namespace RBX {
class BrickColor { public: int number; };
namespace RenderBase { class Mesh : public G3D::ReferenceCountedObject { public: virtual ~Mesh(); }; }
namespace Render = RenderBase;
namespace ViewNew {
class RenderSurfaceTypes
{
public:
    size_t data;
};

struct Lookup
{
    G3D::Vector3 size;
    RenderSurfaceTypes surfaceTypes;
    BrickColor color;
    bool operator<(const Lookup& other) const;
};

struct Variations
{
    int count;
    G3D::ReferenceCountedPointer<Render::Mesh> meshes[4];
};

extern bool useBevels;

class BrickMesh : public Render::Mesh
{
public:
    static float bevel;
    static bool buildingBevel;
    BrickMesh(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes, BrickColor color, void* a, void* b, void* c, float d);
    void buildBevel(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes, BrickColor color);
    char pad[0x88 - sizeof(Render::Mesh)];

    struct Cache
    {
        std::map<Lookup, Variations> cache;
        boost::recursive_mutex mutex;
        int count;
    };
    static Cache* cache;
    static boost::once_flag cacheOnce;
    static void initCache();
    static void flushUnused();
    static G3D::ReferenceCountedPointer<Render::Mesh> create(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes, BrickColor color);
};

G3D::ReferenceCountedPointer<Render::Mesh> BrickMesh::create(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes, BrickColor color)
{
    Lookup lookup = {size, surfaceTypes, color};

    boost::call_once(initCache, cacheOnce);
    Cache* c = cache;
    boost::recursive_mutex::scoped_lock lock(c->mutex);

    Variations& variation = c->cache[lookup];

    size_t mesh = variation.count == 4 ? G3D::iRandom(0, 3) : std::min(3, G3D::iRandom(0, 8));

    G3D::ReferenceCountedPointer<Render::Mesh> thisMesh = variation.meshes[mesh];

    if (thisMesh.isNull())
    {
        buildingBevel = false;
        if (useBevels)
        {
            bevel = 0.065f;
            thisMesh = new BrickMesh(size, surfaceTypes, color, 0, 0, 0, 0.0f);
            bevel = 0.0f;
            buildingBevel = true;
            dynamic_cast<BrickMesh*>(thisMesh.getPointer())->buildBevel(size, surfaceTypes, color);
            buildingBevel = false;
        }
        else
        {
            bevel = 0.0f;
            thisMesh = new BrickMesh(size, surfaceTypes, color, 0, 0, 0, 0.0f);
        }
        variation.meshes[mesh] = thisMesh;
        variation.count++;

        if (++c->count % 100 == 0)
        {
            G3D::ReferenceCountedPointer<Render::Mesh> keep = variation.meshes[mesh];
            flushUnused();
        }
    }

    return thisMesh;
}
}
}
