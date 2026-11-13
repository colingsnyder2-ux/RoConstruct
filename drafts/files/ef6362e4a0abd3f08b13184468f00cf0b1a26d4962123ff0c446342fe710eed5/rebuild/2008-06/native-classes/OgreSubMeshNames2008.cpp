// native-flags: /Od /Ob0 /GS /EHsc /MD /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#include "OgreRbx/VisualEngine2008.h"
namespace Ogre {
SubMeshNames* subMeshNames;
boost::once_flag subMeshNamesOnce = BOOST_ONCE_INIT;
// INFERRED: name from destructor call at 0067a349; original target 0054ab60.
void initializeSubMeshNames() { subMeshNames = new SubMeshNames; }
}
