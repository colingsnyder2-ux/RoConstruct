// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Mesh lifetime: original 00548a90; native fields from original RTTI/member accesses.
#include "ViewNew/RenderBaseMesh.h"
#include "OgreRbx/GeometryCreate2008.h"
#include "OgreRbx/RbxSubMesh2008.h"
#include <OgreLogManager.h>
namespace RBX { namespace RenderBase {
// INFERRED name: original 0054ab40 accesses the shared registry/once state.
static Ogre::GeometryContext* geometryContextForMesh()
{
	boost::call_once(Ogre::initializeGeometryContext, Ogre::geometryOnce);
	return Ogre::geometryContext;
}
Mesh::~Mesh()
{
	if (subMesh) {
		delete subMesh;
		Ogre::GeometryContext* context = geometryContextForMesh();
		boost::recursive_mutex::scoped_lock lock(context->mutex);
		// INFERRED disabled invariant: original retains the release debugAssert loop here.
		debugAssert(context->names.find(subMesh) != context->names.end());
		Ogre::LogManager::getSingleton().logMessage("RBX rm " + context->names[subMesh] + " shd");
		context->names.erase(context->names.find(subMesh));
	}
}
} }
