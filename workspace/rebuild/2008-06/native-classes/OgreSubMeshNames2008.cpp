// native-flags: /Od /Ob0 /GS /EHsc /MD /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#include "OgreRbx/VisualEngine2008.h"
#include <boost/thread/recursive_mutex.hpp>
namespace Ogre {
// INFERRED: map base, zero-initialized counter and recursive mutex from constructor 0054abe0.
struct SubMeshRegistry : SubMeshNames { int count; boost::recursive_mutex mutex; SubMeshRegistry() { count = 0; } };
SubMeshNames* subMeshNames;
boost::once_flag subMeshNamesOnce = BOOST_ONCE_INIT;
void initializeSubMeshNames() { subMeshNames = new SubMeshRegistry; }
}

