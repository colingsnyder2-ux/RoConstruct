// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
template<class T> class Array {
public:
    T* data;
    int num;
    int numAllocated;
    int size() const { return num; }
    T* getCArray() { return data; }
    const T* getCArray() const { return data; }
    T& operator[](int n) { return data[n]; }
    const T& operator[](int n) const { return data[n]; }
};
class VAR { public: char pad[0x48]; };
class GLight;
class RenderDevice {
public:
    enum Primitive { LINES, LINE_STRIP, TRIANGLES };
    void beginIndexedPrimitives();
    void endIndexedPrimitives();
    void setVertexArray(const VAR& v);
    void internalSendIndices(Primitive primitive, int indexSize, int numIndices, const void* index);
    void setVARAreaMilestone();
    void countPrimitive(Primitive primitive, int numVertices);
    template<class T> void sendIndices(Primitive primitive, int numIndices, const T* index)
    {
        internalSendIndices(primitive, sizeof(T), numIndices, index);
        setVARAreaMilestone();
        countPrimitive(primitive, numIndices);
    }
};
}
namespace RBX { namespace Render {
class ShadowCachingChunk {
public:
    virtual ~ShadowCachingChunk();
    virtual void f();
    virtual void renderShadows(G3D::RenderDevice* rd, const G3D::GLight& light, bool caps, float shadowVertexDistance);
};
class RenderScene {
public:
    char pad[0x64];
    G3D::Array<ShadowCachingChunk*> shadowCachingChunkArray;
    G3D::VAR shadowVAR;
    G3D::Array<int> shadowIndexArray;
private:
    void renderShadowVolumeGeometry(G3D::RenderDevice* rd, const G3D::GLight& light, bool caps, float shadowVertexDistance);
};
void RenderScene::renderShadowVolumeGeometry(G3D::RenderDevice* rd, const G3D::GLight& light, bool caps, float shadowVertexDistance)
{
    rd->beginIndexedPrimitives();
    rd->setVertexArray(shadowVAR);
    rd->sendIndices(G3D::RenderDevice::TRIANGLES, shadowIndexArray.size(), shadowIndexArray.getCArray());
    rd->endIndexedPrimitives();

    for (int i = 0; i < shadowCachingChunkArray.size(); i++)
    {
        shadowCachingChunkArray[i]->renderShadows(rd, light, caps, shadowVertexDistance);
    }
}
}}
