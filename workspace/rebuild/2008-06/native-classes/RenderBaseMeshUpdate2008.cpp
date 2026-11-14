// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Shared mesh update: original 005493e0; method and receiver names inferred.
#include "ViewNew/RenderBaseMesh.h"
#include "OgreRbx/GeometryCreate2008.h"
#include <OgreLogManager.h>
namespace RBX { namespace RenderBase {
extern int levelsDestroyed; // original 009738a8; shared with Level destructor
void Mesh::updateGeometry(Ogre::GeometryBuilder* engine)
{
    if (!varDirty) return;
    if (visibleGeometry.vertexArray.size() == 0) return;
    if (!sharedMesh.isNull()) {
        engine->update(sharedMesh, &visibleGeometry.vertexArray[0].x,
            visibleGeometry.vertexArray.size(), &visibleGeometry.normalArray[0].x, NULL,
            &texCoordArray[0].x, NULL, NULL);
        varDirty = false;
    } else if (sharedMesh.isNull()) {
        sharedMesh = engine->create("rbxvb", "General", &visibleGeometry.vertexArray[0].x,
            visibleGeometry.vertexArray.size(), &visibleGeometry.normalArray[0].x, NULL,
            &texCoordArray[0].x, NULL, NULL);
        Ogre::LogManager::getSingleton().logMessage(
            std::string("create mesh=") + sharedMesh->getName() + "\n");
        varDirty = false;
        levelsDestroyed = 0;
    }
}
} }
