// Layout probes for the inactive native Ogre::RbxSceneNode and Ogre::TwoDManager (2008-06).
// Each probe compiles to `mov eax, imm32; ret`; tests/record_native_ogre_rbx_node.py compares the immediates with the
// sizes and offsets read from the original (RbxSceneNode: operator new(0x248) at 00674474 / 007ab230, constructor
// 00674160, the +0x228 map accesses; TwoDManager: operator new(0x58) in 0067bb22, constructor 006831d0, setup 00682560,
// list element 0x30 from _Buynode 00682b20; see the two headers under native-headers/OgreRbxNode/).
// nativeNewRbxSceneNode instantiates the header-inline RbxSceneNode constructor so that this object carries the
// RbxSceneNode vtable and ??_G.
#include "OgreRbxNode/RbxSceneNode2008.h"
#include "OgreRbxNode/TwoDManager2008.h"
#include <stddef.h>

struct NativeOgreRbxNodeLayout
{
	static int size() { return sizeof(Ogre::RbxSceneNode); }
	static int sceneNodeSize() { return sizeof(Ogre::SceneNode); }
	static int transforms() { return offsetof(Ogre::RbxSceneNode, transforms); }
	static int transformMapSize() { return sizeof(Ogre::RbxSceneNode::TransformMap); }
	static int sphereSize() { return sizeof(Ogre::Sphere); }

	static int twoDSize() { return sizeof(Ogre::TwoDManager); }
	static int twoDSceneManager() { return offsetof(Ogre::TwoDManager, sceneManager); }
	static int twoDQueueId() { return offsetof(Ogre::TwoDManager, queueId); }
	static int twoDAfterQueue() { return offsetof(Ogre::TwoDManager, afterQueue); }
	static int twoDFlag() { return offsetof(Ogre::TwoDManager, flag); }
	static int twoDTarget() { return offsetof(Ogre::TwoDManager, target); }
	static int twoDRenderOp() { return offsetof(Ogre::TwoDManager, renderOp); }
	static int twoDVertexBuffer() { return offsetof(Ogre::TwoDManager, vertexBuffer); }
	static int twoDIndexBuffer() { return offsetof(Ogre::TwoDManager, indexBuffer); }
	static int twoDQuads() { return offsetof(Ogre::TwoDManager, quads); }
	static int quadSize() { return sizeof(Ogre::TwoDManager::Quad); }
	static int quadColour() { return offsetof(Ogre::TwoDManager::Quad, colour); }
	static int quadTexture() { return offsetof(Ogre::TwoDManager::Quad, texture); }
	static int quadOperationType() { return offsetof(Ogre::TwoDManager::Quad, operationType); }
	static int quadMode() { return offsetof(Ogre::TwoDManager::Quad, mode); }
};

#define PROBE(name) int nativeOgreRbxNode_##name() { return NativeOgreRbxNodeLayout::name(); }
PROBE(size) PROBE(sceneNodeSize) PROBE(transforms) PROBE(transformMapSize) PROBE(sphereSize)
PROBE(twoDSize) PROBE(twoDSceneManager) PROBE(twoDQueueId) PROBE(twoDAfterQueue) PROBE(twoDFlag) PROBE(twoDTarget)
PROBE(twoDRenderOp) PROBE(twoDVertexBuffer) PROBE(twoDIndexBuffer) PROBE(twoDQuads) PROBE(quadSize) PROBE(quadColour)
PROBE(quadTexture) PROBE(quadOperationType) PROBE(quadMode)

Ogre::RbxSceneNode* nativeNewRbxSceneNode(Ogre::SceneManager* creator, const Ogre::String& name)
{
	return new Ogre::RbxSceneNode(creator, name);
}
