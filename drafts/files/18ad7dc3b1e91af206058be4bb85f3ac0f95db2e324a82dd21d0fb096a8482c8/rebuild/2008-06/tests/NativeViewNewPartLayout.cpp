// Layout probes for the inactive native RBX::ViewNew::PartChunk / Part / Decal / Texture (2008-06).
// Each probe compiles to `mov eax, imm32; ret`; tests/record_native_viewnew_part.py compares the immediates with the
// sizes and offsets read from the original (allocation sizes, constructor stores, destructor accesses).
#include "ViewNew/PartChunk.h"
#include <stddef.h>

struct NativeViewNewPartLayout
{
	typedef RBX::ViewNew::PartChunk PartChunk;
	typedef RBX::ViewNew::Part Part;
	typedef RBX::ViewNew::Decal Decal;
	typedef RBX::ViewNew::Texture Texture;

	static int partChunkSize() { return sizeof(PartChunk); }
	static int partChunkCoordinateFrame() { return offsetof(PartChunk, coordinateFrame); }
	static int partChunkChildAdded() { return offsetof(PartChunk, childAddedConnection); }
	static int partChunkChildRemoved() { return offsetof(PartChunk, childRemovedConnection); }
	static int partChunkAncestorChanged() { return offsetof(PartChunk, ancestorChangedConnection); }
	static int partChunkPropertyChanged() { return offsetof(PartChunk, propertyChangedConnection); }
	static int partChunkShapePropertyChanged() { return offsetof(PartChunk, shapePropertyChangedConnection); }
	static int partChunkPartInstance() { return offsetof(PartChunk, partInstance); }
	static int partChunkMaterial() { return offsetof(PartChunk, material); }
	static int partChunkMaterialInvalid() { return offsetof(PartChunk, materialInvalid); }
	static int partChunkMesh() { return offsetof(PartChunk, mesh); }
	static int partChunkView() { return offsetof(PartChunk, view); }
	static int partChunkSpecialShape() { return offsetof(PartChunk, specialShape); }
	static int scopedConnectionSize() { return sizeof(boost::signals::scoped_connection); }
	static int partSize() { return sizeof(Part); }
	static int partConnection() { return offsetof(Part, connection); }
	static int decalSize() { return sizeof(Decal); }
	static int decalDecal() { return offsetof(Decal, decal); }
	static int decalAncestorChanged() { return offsetof(Decal, decalAncestorChangedConnection); }
	static int decalPropertyChanged() { return offsetof(Decal, decalPropertyChangedConnection); }
	static int textureSize() { return sizeof(Texture); }
	static int textureDecal() { return offsetof(Texture, decal); }
	static int textureAncestorChanged() { return offsetof(Texture, textureAncestorChangedConnection); }
	static int texturePropertyChanged() { return offsetof(Texture, texturePropertyChangedConnection); }
};

#define PROBE(name) int native##name() { return NativeViewNewPartLayout::name(); }
PROBE(partChunkSize)
PROBE(partChunkCoordinateFrame)
PROBE(partChunkChildAdded)
PROBE(partChunkChildRemoved)
PROBE(partChunkAncestorChanged)
PROBE(partChunkPropertyChanged)
PROBE(partChunkShapePropertyChanged)
PROBE(partChunkPartInstance)
PROBE(partChunkMaterial)
PROBE(partChunkMaterialInvalid)
PROBE(partChunkMesh)
PROBE(partChunkView)
PROBE(partChunkSpecialShape)
PROBE(scopedConnectionSize)
PROBE(partSize)
PROBE(partConnection)
PROBE(decalSize)
PROBE(decalDecal)
PROBE(decalAncestorChanged)
PROBE(decalPropertyChanged)
PROBE(textureSize)
PROBE(textureDecal)
PROBE(textureAncestorChanged)
PROBE(texturePropertyChanged)
