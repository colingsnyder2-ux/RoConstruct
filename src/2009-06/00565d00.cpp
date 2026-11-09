// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class CoordinateFrame;
class RenderDevice {
public:
    void setObjectToWorldMatrix(const CoordinateFrame& cframe);
    void setPolygonOffset(double offset);
};
template<class T> class Array {
public:
    T* data; int num;
    int size() const { return num; }
    const T& operator[](int n) const { return data[n]; }
};
}
namespace RBX { namespace Render {
class Mesh { public: static void sendGeometry(Mesh* mesh, G3D::RenderDevice* rd); };
class Level { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void configureRenderDevice(G3D::RenderDevice* rd) const; };
struct RenderSurface {
    char cframe[0x34];
    Level* material;
    float polygonOffset;
    Mesh* mesh;
};
class RenderScene {
public:
    char pad[0x34];
    G3D::Array<RenderSurface*> diffuseProxyArray;
    void sendDiffuseProxyMeshGeometry(G3D::RenderDevice* rd) const;
};
void RenderScene::sendDiffuseProxyMeshGeometry(G3D::RenderDevice* rd) const
{
    for (int i = diffuseProxyArray.size() - 1; i >= 0; i--)
    {
        RenderSurface* current = diffuseProxyArray[i];
        rd->setObjectToWorldMatrix(*reinterpret_cast<const G3D::CoordinateFrame*>(current->cframe));
        rd->setPolygonOffset(current->polygonOffset);
        current->material->configureRenderDevice(rd);
        Mesh::sendGeometry(current->mesh, rd);
    }
}
}}
