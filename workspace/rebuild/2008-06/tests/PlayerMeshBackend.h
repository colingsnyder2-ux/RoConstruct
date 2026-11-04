#pragma once
#include <Ogre.h>
#include <OgreEdgeListBuilder.h>

namespace Ogre {
// 00678470 / 0067c130 prove offsets c4, c8, cc, ec and allocation f0.
class RbxSubMesh : public SubMesh {
public:
    bool prepared;
    EdgeData* edges;
    AxisAlignedBox bounds;
    float radius;
    RbxSubMesh();
    ~RbxSubMesh();
};
}

namespace PlayerMeshBackend {
Ogre::RbxSubMesh* createIndexed(const float* vertices, unsigned vertexCount,
    const float* normals, const float* colours, const float* texCoords,
    const unsigned short* indices16, const unsigned* indices32, unsigned triangles,
    Ogre::Vector3& minimum, Ogre::Vector3& maximum);
void destroyIndexed(Ogre::RbxSubMesh* mesh);
unsigned liveMeshes();
}

// Global map0097dbc4; independent of RbxSceneNode's per-node transform map.
namespace PlayerSphereCache {
typedef unsigned long Key;
void set(Key,const Ogre::Sphere&);
const Ogre::Sphere& get(Key);
bool has(Key);
bool remove(Key);
unsigned size(); // Diagnostic entry count; native empty singleton remains allocated.
}
