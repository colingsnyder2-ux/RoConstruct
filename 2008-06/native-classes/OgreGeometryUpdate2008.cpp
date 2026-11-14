// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#undef OGRE_NONCLIENT_BUILD
#include "OgreRbx/GeometryCreate2008.h"
#include <OgreVertexIndexData.h>
#include <OgreAxisAlignedBox.h>
#include <cmath>

namespace Ogre {
// INFERRED method name; 00679e70 replaces Mesh::sharedVertexData (+0x1e4),
// calls vertex creation at 00679ae0, then sets bounds and half-diagonal radius.
void GeometryBuilder::update(MeshPtr& mesh, const float* vertices, unsigned vertexCount,
    const float* normals, const float* colours, const float* texCoords,
    const Vector3* minimum, const Vector3* maximum)
{
    if (mesh->sharedVertexData) {
        delete mesh->sharedVertexData;
        mesh->sharedVertexData = 0;
    }
    mesh->sharedVertexData = createVertexData(vertices, vertexCount, normals, colours, texCoords);
    Vector3 difference;
    if (minimum && maximum) {
        mesh->_setBounds(AxisAlignedBox(minimum->x, minimum->y, minimum->z,
            maximum->x, maximum->y, maximum->z), true);
        difference.z = maximum->z - minimum->z;
        difference.y = maximum->y - minimum->y;
        difference.x = maximum->x - minimum->x;
        mesh->_setBoundingSphereRadius(static_cast<float>(sqrt(static_cast<double>(difference.squaredLength()))) * 0.5f);
    } else {
        Vector3 low(1.0e9f, 1.0e9f, 1.0e9f), high(-1.0e9f, -1.0e9f, -1.0e9f);
        for (unsigned i = 0; i < 3 * vertexCount; i += 3) {
            if (low.x > vertices[i]) low.x = vertices[i];
            if (low.y > vertices[i + 1]) low.y = vertices[i + 1];
            if (low.z > vertices[i + 2]) low.z = vertices[i + 2];
            if (high.x < vertices[i]) high.x = vertices[i];
            if (high.y < vertices[i + 1]) high.y = vertices[i + 1];
            if (high.z < vertices[i + 2]) high.z = vertices[i + 2];
        }
        mesh->_setBounds(AxisAlignedBox(low.x, low.y, low.z, high.x, high.y, high.z), true);
        difference.z = high.z - low.z;
        difference.y = high.y - low.y;
        difference.x = high.x - low.x;
        mesh->_setBoundingSphereRadius(static_cast<float>(sqrt(static_cast<double>(difference.squaredLength()))) * 0.5f);
    }
}
}
