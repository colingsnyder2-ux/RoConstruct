// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Level lifetime from donor loop and original 005489b0; globals and cleanup name inferred.
#include "ViewNew/RenderBaseMesh.h"
#include <OgreMesh.h>
#include <OgreLogManager.h>
#include <OgreStringConverter.h>
#include "OgreRbx/GeometryCreate2008.h"
#include "OgreRbx/RbxSubMesh2008.h"
namespace Ogre { bool eraseSphere(const void*); } // original 00682150
namespace RBX { namespace RenderBase {
int levelsDestroyed; // inferred name; original 009738a8
Ogre::MeshPtr Mesh::sharedMesh;
static Ogre::GeometryContext* geometryContextForLevel()
{
    boost::call_once(Ogre::initializeGeometryContext, Ogre::geometryOnce);
    return Ogre::geometryContext;
}
void Mesh::Level::invalidate()
{
    dirty = true;
    if (subMesh) {
        delete subMesh;
        Ogre::eraseSphere(subMesh);
        Ogre::GeometryContext* context = geometryContextForLevel();
        boost::recursive_mutex::scoped_lock lock(context->mutex);
        debugAssert(context->names.find(subMesh) != context->names.end());
        Ogre::LogManager::getSingleton().logMessage("RBX rm " + context->names[subMesh]);
        context->names.erase(context->names.find(subMesh));
        subMesh = NULL;
    }
    if (vertexStart > 0) {
        debugAssert(!sharedMesh.isNull());
        unsigned int count = sharedMesh->getNumSubMeshes();
        debugAssert(vertexStart < (int)count);
        Ogre::IndexData*& data = sharedMesh->getSubMesh(vertexStart)->indexData;
        delete data;
        data = NULL;
        Ogre::LogManager::getSingleton().logMessage("RBX rm sm" + Ogre::StringConverter::toString(vertexStart));
        Ogre::eraseSphere(sharedMesh->getSubMesh(vertexStart));
    }
}
Mesh::Level::~Level()
{
    for (int i = 0; i < indexArray.size(); ++i)
        Mesh::freeVertex(indexArray[i]);
    invalidate();
    ++levelsDestroyed;
    if (!sharedMesh.isNull())
        sharedMesh->getNumSubMeshes();
}
} }
