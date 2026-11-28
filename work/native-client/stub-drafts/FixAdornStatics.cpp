// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#include <string>
#include <OgreMesh.h>
#include <OgreMaterial.h>

Ogre::MeshPtr rocAdornCylinderMesh;
Ogre::MeshPtr rocAdornSphereMesh;
Ogre::MaterialPtr rocExplosionMaterial;
std::string rocRenderDeviceString;
std::string rocNetworkVersion;
