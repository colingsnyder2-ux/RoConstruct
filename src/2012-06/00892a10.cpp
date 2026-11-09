// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// roc-lib: rbxgs-render roc_manual_aggregate_6f70ce73a8fc22b3.cpp

// Candidate translation unit (score above; library headers required).
#include "RenderLib/TextureProxy.h"
#include "RenderLib/RenderStats.h"
#include <G3D/GLight.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/ReferenceCount.h>
#include <GLG3D/RenderDevice.h>
#include <GLG3D/VAR.h>
#include <vector>

namespace RBX { namespace Render {
class AggregateChunk;
class Mesh : public G3D::ReferenceCountedObject {};
class Material : public G3D::ReferenceCountedObject {
public:
    class Level {};
    virtual ~Material();
    virtual void oldMethod();
    virtual const Level& appendEmptyLevel();
    virtual const Level& appendLevel(G3D::Color3, float, float, float, float);
    virtual const Level& appendLevel(G3D::ReferenceCountedPointer<TextureProxy>, G3D::Color3, float, float, float, float);
};
Material* createMaterial();

class __declspec(novtable) Chunk : public G3D::ReferenceCountedObject {
    char oldBaseMembers[12];
public:
    const float polygonOffset;
    float radius;
    G3D::WeakReferenceCountedPointer<AggregateChunk> aggregate;
    virtual bool cachesShadows() const { return false; }
    virtual void renderShadows(G3D::RenderDevice*, const G3D::GLight&, bool, float) {}
    virtual bool castsShadows() const = 0;
    virtual bool cullable() const = 0;
    virtual G3D::ReferenceCountedPointer<Material> getMaterial() = 0;
    virtual G3D::ReferenceCountedPointer<Mesh> getMesh() = 0;
    virtual const G3D::CoordinateFrame& cframe() = 0;
    Chunk(float value) : polygonOffset(value), radius(G3D::inf()) { RenderStats::chunkCount++; }
    virtual ~Chunk() { RenderStats::chunkCount--; }
};

class AggregateChunk : public Chunk {
    G3D::ReferenceCountedPointer<Material> material;
    G3D::ReferenceCountedPointer<Mesh> mesh;
    G3D::CoordinateFrame _cframe;
    bool _castsShadows;
    bool _cullable;
    char oldMembers[4];
    G3D::GLight shadowSource;
    G3D::VAR shadowVAR;
    G3D::Array<unsigned int> shadowIndexArray;
    G3D::Array<unsigned short> shadowIndexArray16;
public:
    std::vector<G3D::ReferenceCountedPointer<Chunk> > components;
    static bool randomColors;
    virtual bool castsShadows() const { return _castsShadows; }
    virtual bool cullable() const { return _cullable; }
    virtual void renderShadows(G3D::RenderDevice*, const G3D::GLight&, bool, float);
    AggregateChunk(const G3D::ReferenceCountedPointer<Chunk>& firstChunk);
    virtual ~AggregateChunk();
    virtual bool cachesShadows() const;
    virtual G3D::ReferenceCountedPointer<Material> getMaterial() { return material; }
    virtual G3D::ReferenceCountedPointer<Mesh> getMesh() { return mesh; }
    virtual const G3D::CoordinateFrame& cframe() { return _cframe; }
};

AggregateChunk::AggregateChunk(const G3D::ReferenceCountedPointer<Chunk>& firstChunk)
    : Chunk(firstChunk->polygonOffset),
      _castsShadows(firstChunk->castsShadows()),
      _cullable(firstChunk->cullable())
{
    if (!randomColors)
        material = firstChunk->getMaterial();
    RenderStats::aggregateChunkCount++;
    RenderStats::chunkCount--;
    if (randomColors) {
        material = createMaterial();
        material->appendLevel(NULL, (G3D::Color3::wheelRandom() + G3D::Color3::white()) / 2.0f, 0.0f, 50.0f, 0.0f, 0.0f);
    }
}
} }
