// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Original registry initializer 0054ab60; names and types inferred from member accesses.
#include "OgreRbx/GeometryCreate2008.h"
namespace Ogre {
GeometryContext* geometryContext;
boost::once_flag geometryOnce = BOOST_ONCE_INIT;
void initializeGeometryContext()
{
    geometryContext = new GeometryContext;
}
}
