#pragma once
// >>> native-status (generated) -- do not edit >>>
// GeometryCreate2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src b3977b7f | roc native-status --write
#include <OgreMesh.h>
#include <OgreVector3.h>
#include <boost/thread/recursive_mutex.hpp>
#include <boost/thread/once.hpp>
#include <map>
namespace Ogre {
// INFERRED: receiver/method names and pointer signatures from 0067bcc0 analog; target preserves this for update call.
class RbxSubMesh;
class GeometryBuilder {
public:
    VertexData* createVertexData(const float*, unsigned, const float*, const float*, const float*);
    RbxSubMesh* createIndexed(const float*, unsigned, const float*, const float*, const float*, const unsigned short*, const unsigned*, unsigned, Vector3*, Vector3*);
    void update(MeshPtr&, const float*, unsigned, const float*, const float*, const float*, const Vector3*, const Vector3*);
    MeshPtr create(const char*, const char*, const float*, unsigned, const float*, const float*, const float*, const Vector3*, const Vector3*);
};
// INFERRED: context member names; 0067c130 accesses SubMesh->String map at +0, counter +0x20; 0067bcc0 locks +0x24.
struct GeometryContext {
    std::map<RbxSubMesh*, String> names;
    int counter;
    boost::recursive_mutex mutex;
};
// INFERRED: context/once/initializer names; original 0097db44, 00973984, 0054ab60 respectively.
extern GeometryContext* geometryContext;
extern boost::once_flag geometryOnce;
void initializeGeometryContext();
}
