// Layout probes for the Ogre 1.4.5 classes the June 2008 client constructs from rgmain.dll (inactive; 2008-06).
// Each probe compiles to `mov eax, imm32; ret`; tests/record_native_ogre_rbx_locals.py compares the immediates with the
// operator new sizes at the construction sites and with the RTTI base offsets (see
// native-headers/OgreRbxLocals/OgreLocals2008.h). The nativeNew* functions construct each class with the constructor the
// client imports, so that this object carries the exe-local vftables, ??_G and ??_E thunks MSVC emits for these
// __declspec(dllimport) classes. They are probe scaffolding, not recovered functions.
#include "OgreRbxLocals/OgreLocals2008.h"

namespace
{
	template <class D, class B> int baseOffset()
	{
		D* p = reinterpret_cast<D*>(0x1000);
		return reinterpret_cast<char*>(static_cast<B*>(p)) - reinterpret_cast<char*>(p);
	}
}

int nativeOgreRbxLocals_manualObjectSize() { return sizeof(Ogre::ManualObject); }
int nativeOgreRbxLocals_rectangle2DSize() { return sizeof(Ogre::Rectangle2D); }
int nativeOgreRbxLocals_instancedGeometrySize() { return sizeof(Ogre::InstancedGeometry); }
int nativeOgreRbxLocals_staticGeometrySize() { return sizeof(Ogre::StaticGeometry); }
int nativeOgreRbxLocals_sceneNodeSize() { return sizeof(Ogre::SceneNode); }
int nativeOgreRbxLocals_memoryDataStreamSize() { return sizeof(Ogre::MemoryDataStream); }
int nativeOgreRbxLocals_fileStreamDataStreamSize() { return sizeof(Ogre::FileStreamDataStream); }
int nativeOgreRbxLocals_renderQueueSize() { return sizeof(Ogre::RenderQueue); }
int nativeOgreRbxLocals_animationSize() { return sizeof(Ogre::Animation); }
int nativeOgreRbxLocals_manualObjectAnimable() { return baseOffset<Ogre::ManualObject, Ogre::AnimableObject>(); }
int nativeOgreRbxLocals_rectangle2DAnimable() { return baseOffset<Ogre::Rectangle2D, Ogre::AnimableObject>(); }
int nativeOgreRbxLocals_rectangle2DRenderable() { return baseOffset<Ogre::Rectangle2D, Ogre::Renderable>(); }

Ogre::MovableObject* nativeNewManualObject(const Ogre::String& name) { return new Ogre::ManualObject(name); }
Ogre::MovableObject* nativeNewRectangle2D(bool includeTextureCoordinates)
{ return new Ogre::Rectangle2D(includeTextureCoordinates); }
Ogre::InstancedGeometry* nativeNewInstancedGeometry(Ogre::SceneManager* owner, const Ogre::String& name)
{ return new Ogre::InstancedGeometry(owner, name); }
Ogre::StaticGeometry* nativeNewStaticGeometry(Ogre::SceneManager* owner, const Ogre::String& name)
{ return new Ogre::StaticGeometry(owner, name); }
Ogre::SceneNode* nativeNewSceneNode(Ogre::SceneManager* creator) { return new Ogre::SceneNode(creator); }
Ogre::SceneNode* nativeNewNamedSceneNode(Ogre::SceneManager* creator, const Ogre::String& name)
{ return new Ogre::SceneNode(creator, name); }
Ogre::DataStream* nativeNewMemoryDataStream(void* memory, size_t size)
{ return new Ogre::MemoryDataStream(memory, size, false); }
Ogre::DataStream* nativeNewFileStreamDataStream(std::ifstream* stream)
{ return new Ogre::FileStreamDataStream(stream, false); }
Ogre::RenderQueue* nativeNewRenderQueue() { return new Ogre::RenderQueue(); }
Ogre::Animation* nativeNewAnimation(const Ogre::String& name, Ogre::Real length)
{ return new Ogre::Animation(name, length); }
