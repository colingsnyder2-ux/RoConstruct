// Layout probes for the inactive native RBX::AdornRbxGfx (2008-06).
// Each probe compiles to `mov eax, imm32; ret`; tests/record_native_adorn.py compares the immediates with the size and
// offsets read from the original (operator new(0x144) in 0045b425, constructor 00674210 / 006743eb, the vector, map and
// Ogre pointer accesses listed in native-headers/RbxGraphics/AdornRbxGfx2008.h).
#include "RbxGraphics/AdornRbxGfx2008.h"
#include <stddef.h>

struct NativeAdornRbxGfxLayout
{
	static int size() { return sizeof(RBX::AdornRbxGfx); }
	static int visualEngine() { return offsetof(RBX::AdornRbxGfx, visualEngine); }
	static int texture2d() { return offsetof(RBX::AdornRbxGfx, texture2d); }
	static int textureMaterial() { return offsetof(RBX::AdornRbxGfx, textureMaterial); }
	static int rootNode() { return offsetof(RBX::AdornRbxGfx, rootNode); }
	static int renderNode() { return offsetof(RBX::AdornRbxGfx, renderNode); }
	static int solidMaterial() { return offsetof(RBX::AdornRbxGfx, solidMaterial); }
	static int particleCount() { return offsetof(RBX::AdornRbxGfx, particleCount); }
	static int freeSubEntities() { return offsetof(RBX::AdornRbxGfx, freeSubEntities); }
	static int usedSubEntities() { return offsetof(RBX::AdornRbxGfx, usedSubEntities); }
	static int meshes() { return offsetof(RBX::AdornRbxGfx, meshes); }
	static int entity() { return offsetof(RBX::AdornRbxGfx, entity); }
	static int explosionRoot() { return offsetof(RBX::AdornRbxGfx, explosionRoot); }
	static int explosionNodes() { return offsetof(RBX::AdornRbxGfx, explosionNodes); }
	static int explosions() { return offsetof(RBX::AdornRbxGfx, explosions); }
	static int sparkleRoot() { return offsetof(RBX::AdornRbxGfx, sparkleRoot); }
	static int sparkleNodes() { return offsetof(RBX::AdornRbxGfx, sparkleNodes); }
	static int sparkles() { return offsetof(RBX::AdornRbxGfx, sparkles); }
	static int objectToWorld() { return offsetof(RBX::AdornRbxGfx, objectToWorld); }
	static int materialPtrSize() { return sizeof(Ogre::MaterialPtr); }
	static int meshMapSize() { return sizeof(std::map<std::string, Ogre::MeshPtr>); }
	static int nodeVectorSize() { return sizeof(std::vector<Ogre::SceneNode*>); }
};

#define PROBE(name) int nativeAdornRbxGfx_##name() { return NativeAdornRbxGfxLayout::name(); }
PROBE(size) PROBE(visualEngine) PROBE(texture2d) PROBE(textureMaterial) PROBE(rootNode) PROBE(renderNode)
PROBE(solidMaterial) PROBE(particleCount) PROBE(freeSubEntities) PROBE(usedSubEntities) PROBE(meshes) PROBE(entity)
PROBE(explosionRoot) PROBE(explosionNodes) PROBE(explosions) PROBE(sparkleRoot) PROBE(sparkleNodes) PROBE(sparkles)
PROBE(objectToWorld) PROBE(materialPtrSize) PROBE(meshMapSize) PROBE(nodeVectorSize)
