// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Ogre 1.4.5 client-import header code the June 2008 exe compiled locally (inactive native recovery).
//
// Evidence (original Roblox.exe):
//   * SharedPtr<T> scalar deleting destructors, 55 bytes each, release() inlined (vptr reset, --*pUseCount, virtual
//     destroy, optional operator delete): 004d73e0 SharedPtr<Resource>, 004d7420 SharedPtr<DataStream>,
//     0068de40 SharedPtr<GpuProgramParameters>, 0068de80 SharedPtr<ShadowCameraSetup>.
//   * 31-byte local scalar deleting destructors that call the rgmain.dll-imported destructor, e.g. 004dab30
//     (MemoryDataStream, __imp_??1MemoryDataStream@Ogre@@UAE@XZ), 006700c0 FileStreamDataStream, 0069a220 Camera,
//     0069a2e0 SceneNode: the exe deletes objects of these imported classes through their static type.
#include "OgreDataStream.h"
#include "OgreResource.h"
#include "OgreGpuProgram.h"
#include "OgreShadowCameraSetup.h"
#include "OgreCamera.h"
#include "OgreSceneNode.h"
#include "OgreManualObject.h"
#include "OgreRenderQueue.h"
#include "OgreSceneManager.h"
#include "OgreRectangle2D.h"
#include "OgreAnimation.h"
#include "OgreStaticGeometry.h"
#include "OgreInstancedGeometry.h"
#include "OgreRbx/RbxSky2008.h"

template class Ogre::SharedPtr<Ogre::Resource>;
template class Ogre::SharedPtr<Ogre::DataStream>;
template class Ogre::SharedPtr<Ogre::GpuProgramParameters>;
template class Ogre::SharedPtr<Ogre::ShadowCameraSetup>;
template class Ogre::SharedPtr<Ogre::RbxSky>;     // 0068dec0 stores vtable 0084ec3c

// INFERRED: the exe's callers construct and delete these imported classes locally; deleting through the exact
// static type makes the compiler emit the local scalar deleting destructor the binary has.
void ogre_client_delete_memory_stream(Ogre::MemoryDataStream* stream) { delete stream; }
void ogre_client_delete_file_stream(Ogre::FileStreamDataStream* stream) { delete stream; }
void ogre_client_delete_camera(Ogre::Camera* camera) { delete camera; }
void ogre_client_delete_scene_node(Ogre::SceneNode* node) { delete node; }
void ogre_client_delete_manual_object(Ogre::ManualObject* object) { delete object; }
void ogre_client_delete_render_queue(Ogre::RenderQueue* queue) { delete queue; }
void ogre_client_delete_rectangle(Ogre::Rectangle2D* rectangle) { delete rectangle; }
void ogre_client_delete_animation(Ogre::Animation* animation) { delete animation; }
void ogre_client_delete_static_geometry(Ogre::StaticGeometry* geometry) { delete geometry; }
void ogre_client_delete_instanced_geometry(Ogre::InstancedGeometry* geometry) { delete geometry; }
void ogre_client_delete_ray_query(Ogre::DefaultRaySceneQuery* query) { delete query; }
void ogre_client_delete_box_query(Ogre::DefaultAxisAlignedBoxSceneQuery* query) { delete query; }
void ogre_client_delete_sphere_query(Ogre::DefaultSphereSceneQuery* query) { delete query; }
void ogre_client_delete_volume_query(Ogre::DefaultPlaneBoundedVolumeListSceneQuery* query) { delete query; }
void ogre_client_delete_intersection_query(Ogre::DefaultIntersectionSceneQuery* query) { delete query; }
