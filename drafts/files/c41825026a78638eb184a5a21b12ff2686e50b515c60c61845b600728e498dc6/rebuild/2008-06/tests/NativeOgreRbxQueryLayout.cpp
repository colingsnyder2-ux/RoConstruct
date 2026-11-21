// Layout probes for Ogre 1.4.5's default scene queries as compiled into the June 2008 client (inactive; 2008-06).
// Each probe compiles to `mov eax, imm32; ret`; tests/record_native_ogre_rbx_query.py compares the immediates with the
// operator new sizes of RbxSceneManager::create*Query 0068cad0 / 0068cb80 / 0068cc30 / 0068cce0 / 0068cd90 and the
// listener-base offset 0x34 (RTTI mdisp, and the second vptr store at +0x34 after each imported constructor call).
// The nativeNew* functions construct each class the way the RbxSceneManager fork does, so that this object carries the
// exe-local vtables, ??_G and +0x34 ??_E thunks MSVC emits for these __declspec(dllimport) classes (see
// native-headers/OgreRbxQuery/DefaultSceneQueries2008.h). They are probe scaffolding, not recovered functions.
#include "OgreRbxQuery/DefaultSceneQueries2008.h"

namespace
{
	template <class Q, class L> int listenerOffset()
	{
		Q* q = reinterpret_cast<Q*>(0x1000);
		return reinterpret_cast<char*>(static_cast<L*>(q)) - reinterpret_cast<char*>(q);
	}
}

int nativeOgreRbxQuery_aabbSize() { return sizeof(Ogre::DefaultAxisAlignedBoxSceneQuery); }
int nativeOgreRbxQuery_sphereSize() { return sizeof(Ogre::DefaultSphereSceneQuery); }
int nativeOgreRbxQuery_volumeSize() { return sizeof(Ogre::DefaultPlaneBoundedVolumeListSceneQuery); }
int nativeOgreRbxQuery_raySize() { return sizeof(Ogre::DefaultRaySceneQuery); }
int nativeOgreRbxQuery_intersectionSize() { return sizeof(Ogre::DefaultIntersectionSceneQuery); }
int nativeOgreRbxQuery_aabbListener()
{ return listenerOffset<Ogre::DefaultAxisAlignedBoxSceneQuery, Ogre::SceneQueryListener>(); }
int nativeOgreRbxQuery_sphereListener()
{ return listenerOffset<Ogre::DefaultSphereSceneQuery, Ogre::SceneQueryListener>(); }
int nativeOgreRbxQuery_volumeListener()
{ return listenerOffset<Ogre::DefaultPlaneBoundedVolumeListSceneQuery, Ogre::SceneQueryListener>(); }
int nativeOgreRbxQuery_rayListener()
{ return listenerOffset<Ogre::DefaultRaySceneQuery, Ogre::RaySceneQueryListener>(); }
int nativeOgreRbxQuery_intersectionListener()
{ return listenerOffset<Ogre::DefaultIntersectionSceneQuery, Ogre::IntersectionSceneQueryListener>(); }

Ogre::SceneQuery* nativeNewDefaultAxisAlignedBoxSceneQuery(Ogre::SceneManager* creator)
{ return new Ogre::DefaultAxisAlignedBoxSceneQuery(creator); }
Ogre::SceneQuery* nativeNewDefaultSphereSceneQuery(Ogre::SceneManager* creator)
{ return new Ogre::DefaultSphereSceneQuery(creator); }
Ogre::SceneQuery* nativeNewDefaultPlaneBoundedVolumeListSceneQuery(Ogre::SceneManager* creator)
{ return new Ogre::DefaultPlaneBoundedVolumeListSceneQuery(creator); }
Ogre::SceneQuery* nativeNewDefaultRaySceneQuery(Ogre::SceneManager* creator)
{ return new Ogre::DefaultRaySceneQuery(creator); }
Ogre::SceneQuery* nativeNewDefaultIntersectionSceneQuery(Ogre::SceneManager* creator)
{ return new Ogre::DefaultIntersectionSceneQuery(creator); }
