// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /DOGRE_STATIC_LIB /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Local copies of rgmain.dll's CONST static data members. Native Ogre drafts were compiled without dllimport, so
// their direct references to these exports resolved to lld's jmp thunks (garbage reads: Renderable::getClipPlanes
// handed rgdx.dll the thunk bytes as a PlaneList -> crash rendering the first script-parented Part). The values are
// immutable, so an exe-local definition (which wins over the import) is equivalent. Definitions copied from the Ogre
// 1.4.5 sources (OgreVector3.cpp, OgreMatrix4.cpp, OgreQuaternion.cpp, OgreMath.cpp, OgreString.cpp,
// OgreRenderable.cpp, OgreHardwareBufferManager.cpp, OgreBillboardChain.cpp, OgreSceneManagerEnumerator.cpp,
// OgreCompiler2Pass.h). Mutable statics (msDictionary, msDirtyHashList...) must stay the DLL's: not defined here.
#include "OgreVector3.h"
#include "OgreMatrix4.h"
#include "OgreQuaternion.h"
#include "OgreMath.h"
#include "OgreString.h"
#include "OgreRenderable.h"
#include "OgreHardwareBufferManager.h"
#include "OgreBillboardChain.h"
#include "OgreSceneManagerEnumerator.h"
#include "OgreCompiler2Pass.h"
#include "OgreSceneManager.h"
#include "OgreResourceGroupManager.h"
#include "OgreBillboardSet.h"
#include "OgreEntity.h"
#include "OgreRenderQueueInvocation.h"
#include <limits>
#include <cmath>

namespace Ogre
{
    const Vector3 Vector3::ZERO( 0, 0, 0 );
    const Vector3 Vector3::UNIT_X( 1, 0, 0 );
    const Vector3 Vector3::UNIT_Y( 0, 1, 0 );
    const Vector3 Vector3::UNIT_Z( 0, 0, 1 );
    const Matrix4 Matrix4::IDENTITY(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1 );
    const Quaternion Quaternion::IDENTITY(1.0,0.0,0.0,0.0);
    const Real Math::POS_INFINITY = std::numeric_limits<Real>::infinity();
    const Real Math::PI = Real( 4.0 * atan( 1.0 ) );
    const Real Math::TWO_PI = Real( 2.0 * PI );
    const Real Math::HALF_PI = Real( 0.5 * PI );
    const Real Math::fDeg2Rad = PI / Real(180.0);
    const Real Math::fRad2Deg = Real(180.0) / PI;
    const String StringUtil::BLANK;
    const PlaneList Renderable::msDummyPlaneList;
    const size_t HardwareBufferManager::UNDER_USED_FRAME_THRESHOLD = 30000;
    const size_t HardwareBufferManager::EXPIRED_DELAY_FRAME_THRESHOLD = 5;
    const size_t BillboardChain::SEGMENT_EMPTY = 0xffffffff;
    const String DefaultSceneManagerFactory::FACTORY_TYPE_NAME = "DefaultSceneManager";
    const size_t Compiler2Pass::SystemTokenBase;
    // Non-const in type but never assigned after static init in Ogre 1.4.5 (OgreSceneManager.cpp 78-83,
    // OgreResourceGroupManager.cpp 50-56, the *Factory.cpp FACTORY_TYPE_NAME, OgreRenderQueueInvocation.cpp 37).
    // gemini dll_data_audit.json listed them among the 71 mutable thunked imports. Real runtime state
    // (msDictionary, msDirtyHashList, Compiler2Pass maps, msDefault* with setters) stays the DLL's.
    uint32 SceneManager::WORLD_GEOMETRY_TYPE_MASK = 0x80000000;
    uint32 SceneManager::ENTITY_TYPE_MASK = 0x40000000;
    uint32 SceneManager::FX_TYPE_MASK = 0x20000000;
    uint32 SceneManager::STATICGEOMETRY_TYPE_MASK = 0x10000000;
    uint32 SceneManager::LIGHT_TYPE_MASK = 0x08000000;
    uint32 SceneManager::USER_TYPE_MASK_LIMIT = SceneManager::LIGHT_TYPE_MASK;
    String ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME = "General";
    String ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME = "Internal";
    String ResourceGroupManager::BOOTSTRAP_RESOURCE_GROUP_NAME = "Bootstrap";
    String ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME = "Autodetect";
    size_t ResourceGroupManager::RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS = 3;
    String BillboardChainFactory::FACTORY_TYPE_NAME = "BillboardChain";
    String BillboardSetFactory::FACTORY_TYPE_NAME = "BillboardSet";
    String EntityFactory::FACTORY_TYPE_NAME = "Entity";
    String RenderQueueInvocation::RENDER_QUEUE_INVOCATION_SHADOWS = "SHADOWS";
}
