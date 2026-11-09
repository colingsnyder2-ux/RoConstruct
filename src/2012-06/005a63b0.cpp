// roc-cl: 50727
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_meshfac_c11e8ada3ae173a3.cpp

// Candidate translation unit (score above; library headers required).

#include <boost/thread/mutex.hpp>
#include <boost/thread/once.hpp>
#include <G3D/Vector3.h>
#include <G3D/Vector2.h>
#include <G3D/ReferenceCount.h>
#include <map>

namespace RBX {

enum NormalId {
    NORM_X = 0,
    NORM_Y = 1,
    NORM_Z = 2
};

namespace Render {
class Mesh : public G3D::ReferenceCountedObject {
public:
    virtual ~Mesh();
};
}

namespace View {

class RenderSurfaceTypes {
public:
    unsigned int data;
};

#define DEFINE_MESH(Name) class Name : public Render::Mesh { public:     char padding[0x80];     Name(const G3D::Vector3& size, NormalId face);     Name(const G3D::Vector3& size, NormalId face, const G3D::Vector2& studsPerTile);     virtual ~Name(); };

DEFINE_MESH(PBBMesh)
DEFINE_MESH(WedgeMesh)
DEFINE_MESH(TorsoMesh)
DEFINE_MESH(SphereMesh)
DEFINE_MESH(CylinderAlongXMesh)
DEFINE_MESH(HeadMesh)

template <class T, int N>
class MeshFactory {
public:
    class DecalKey {
    public:
        G3D::Vector3 size;
        NormalId face;

        DecalKey(NormalId face, const G3D::Vector3& size) : size(size), face(face) {}
        bool operator<(const DecalKey& other) const {
            if (size.x != other.size.x) return size.x < other.size.x;
            if (size.y != other.size.y) return size.y < other.size.y;
            if (size.z != other.size.z) return size.z < other.size.z;
            return face < other.face;
        }
    };

    class TextureKey {
    public:
        G3D::Vector3 size;
        NormalId face;
        G3D::Vector2 studsPerTile;

        TextureKey(NormalId face, const G3D::Vector3& size, const G3D::Vector2& studsPerTile)
            : size(size), face(face), studsPerTile(studsPerTile) {}
        bool operator<(const TextureKey& other) const {
            if (size.x != other.size.x) return size.x < other.size.x;
            if (size.y != other.size.y) return size.y < other.size.y;
            if (size.z != other.size.z) return size.z < other.size.z;
            if (face != other.face) return face < other.face;
            if (studsPerTile.x != other.studsPerTile.x) return studsPerTile.x < other.studsPerTile.x;
            return studsPerTile.y < other.studsPerTile.y;
        }
    };

    struct Slot {
        T* pointer;
        void operator=(T*);
    };

    typedef std::map<DecalKey, Slot> DecalCache;
    typedef std::map<TextureKey, Slot> TextureCache;

    struct CacheData {
        char padding[0x10];
        boost::mutex mutex;
        char pad[4];
        DecalCache decalCache;
        TextureCache textureCache;
    };

    static CacheData* cacheData;
    static boost::once_flag onceFlag;
    static void initCache();

    static T* createDecal(const G3D::Vector3& size, NormalId face);
    static T* createTexture(const G3D::Vector3& size, NormalId face, const G3D::Vector2& studsPerTile);
};

template <class T, int N>
typename MeshFactory<T, N>::CacheData* MeshFactory<T, N>::cacheData = 0;

template <class T, int N>
boost::once_flag MeshFactory<T, N>::onceFlag = BOOST_ONCE_INIT;

template <class T, int N>
T* MeshFactory<T, N>::createDecal(const G3D::Vector3& size, NormalId face)
{
    boost::call_once(&initCache, onceFlag);
    CacheData* s = cacheData;
    boost::mutex::scoped_lock lock(s->mutex);

    DecalKey key(face, size);
    typename DecalCache::iterator iter = s->decalCache.find(key);

    if (iter == s->decalCache.end()) {
        T* mesh = new T(size, face);
        Slot& slot = s->decalCache[key];
        slot = mesh;
        return mesh;
    }

    return iter->second.pointer;
}

template <class T, int N>
T* MeshFactory<T, N>::createTexture(const G3D::Vector3& size, NormalId face, const G3D::Vector2& studsPerTile)
{
    boost::call_once(&initCache, onceFlag);
    CacheData* s = cacheData;
    boost::mutex::scoped_lock lock(s->mutex);

    TextureKey key(face, size, studsPerTile);
    typename TextureCache::iterator iter = s->textureCache.find(key);

    if (iter == s->textureCache.end()) {
        T* mesh = new T(size, face, studsPerTile);
        Slot& slot = s->textureCache[key];
        slot = mesh;
        return mesh;
    }

    return iter->second.pointer;
}

template PBBMesh* MeshFactory<PBBMesh, 3>::createDecal(const G3D::Vector3&, NormalId);
template PBBMesh* MeshFactory<PBBMesh, 3>::createTexture(const G3D::Vector3&, NormalId, const G3D::Vector2&);

template WedgeMesh* MeshFactory<WedgeMesh, 0>::createDecal(const G3D::Vector3&, NormalId);
template WedgeMesh* MeshFactory<WedgeMesh, 0>::createTexture(const G3D::Vector3&, NormalId, const G3D::Vector2&);

template TorsoMesh* MeshFactory<TorsoMesh, 0>::createDecal(const G3D::Vector3&, NormalId);
template TorsoMesh* MeshFactory<TorsoMesh, 0>::createTexture(const G3D::Vector3&, NormalId, const G3D::Vector2&);

template SphereMesh* MeshFactory<SphereMesh, 0>::createDecal(const G3D::Vector3&, NormalId);
template SphereMesh* MeshFactory<SphereMesh, 0>::createTexture(const G3D::Vector3&, NormalId, const G3D::Vector2&);

template CylinderAlongXMesh* MeshFactory<CylinderAlongXMesh, 0>::createDecal(const G3D::Vector3&, NormalId);
template CylinderAlongXMesh* MeshFactory<CylinderAlongXMesh, 0>::createTexture(const G3D::Vector3&, NormalId, const G3D::Vector2&);

template HeadMesh* MeshFactory<HeadMesh, 0>::createDecal(const G3D::Vector3&, NormalId);
template HeadMesh* MeshFactory<HeadMesh, 0>::createTexture(const G3D::Vector3&, NormalId, const G3D::Vector2&);

}
}
