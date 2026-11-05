// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace G3D {
class Vector2 {
public:
    float x, y;
    Vector2() {}
    Vector2(float _x, float _y) : x(_x), y(_y) {}
    Vector2(const Vector2& v) { x = v.x; y = v.y; }
    Vector2& operator=(const Vector2& v) { x = v.x; y = v.y; return *this; }
    Vector2 operator*(float s) const { return Vector2(x * s, y * s); }
    Vector2 operator/(const Vector2& v) const { return Vector2(x / v.x, y / v.y); }
};
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3& V) : x(V.x), y(V.y), z(V.z) {}
    Vector2 xy() const;
};
class AtomicInt32 {
    volatile long _value;
public:
    void increment() { InterlockedIncrement(&_value); }
    unsigned int decrement() { return InterlockedDecrement(&_value) != 0; }
};
class ReferenceCountedObject {
public:
    AtomicInt32 ReferenceCountedObject_refCount;
    void* ReferenceCountedObject_weakPointer;
    void ReferenceCountedObject_zeroWeakPointers();
    virtual ~ReferenceCountedObject() {}
};
template <class T>
class ReferenceCountedPointer {
private:
    T* m_pointer;
    void zeroPointer() {
        if (m_pointer != 0) {
            if (m_pointer->ReferenceCountedObject_refCount.decrement() == 0) {
                m_pointer->ReferenceCountedObject_zeroWeakPointers();
                delete m_pointer;
            }
            m_pointer = 0;
        }
    }
    void setPointer(T* x) {
        if (x != m_pointer) {
            zeroPointer();
            if (x != 0) {
                m_pointer = x;
                m_pointer->ReferenceCountedObject_refCount.increment();
            }
        }
    }
public:
    ReferenceCountedPointer() : m_pointer(0) {}
    ReferenceCountedPointer(T* p) : m_pointer(0) { setPointer(p); }
    ~ReferenceCountedPointer() { zeroPointer(); }
};
template <class T>
class Array {
    T* data;
    int num;
    int numAllocated;
public:
    void push_back(const T& value);
};
class RenderDevice { public: enum Primitive { QUADS = 5 }; };
}
namespace RBX {
enum NormalId { NORM_X };
namespace Render {
class Mesh : public G3D::ReferenceCountedObject {
public:
    class Level : public G3D::ReferenceCountedObject {
    public:
        Level(G3D::RenderDevice::Primitive primitive);
        char pad[0x28 - 0xc];
    };
    Mesh();
    virtual ~Mesh();
protected:
    G3D::Array<G3D::ReferenceCountedPointer<Level> > levels;
};
}
namespace View {
class RenderSurfaceTypes { public: unsigned int data; RenderSurfaceTypes() : data(0) {} };
G3D::Vector3 mapToUvw_Legacy(const G3D::Vector3& size, NormalId face);
class LevelBuilder {
public:
    enum Usage { Surface = 0, Decal = 1 };
    LevelBuilder(const G3D::ReferenceCountedPointer<Render::Mesh::Level>& level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes);
    virtual void buildFace(NormalId face, Usage usage);
protected:
    char pad[0x14 - 4];
    G3D::ReferenceCountedPointer<Render::Mesh::Level> level;
public:
    G3D::Vector2 textureScale;
};
extern float bevelDefault;
class WedgeBuilder : public LevelBuilder {
    float sides;
public:
    WedgeBuilder(const G3D::ReferenceCountedPointer<Render::Mesh::Level>& level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes)
        : LevelBuilder(level, size, surfaceTypes), sides(bevelDefault) {}
    virtual void buildFace(NormalId face, Usage usage);
};
class WedgeMesh : public Render::Mesh {
public:
    WedgeMesh(const G3D::Vector3& size, NormalId textureFace, const G3D::Vector2& studsPerTile);
};
WedgeMesh::WedgeMesh(const G3D::Vector3& size, NormalId textureFace, const G3D::Vector2& studsPerTile)
{
    G3D::ReferenceCountedPointer<Render::Mesh::Level> level = new Render::Mesh::Level(G3D::RenderDevice::QUADS);
    levels.push_back(level);

    WedgeBuilder builder(level, size, RenderSurfaceTypes());
    builder.textureScale = mapToUvw_Legacy(size, textureFace).xy() * 2.0f / studsPerTile;

    builder.buildFace(textureFace, LevelBuilder::Decal);
}
}
}
