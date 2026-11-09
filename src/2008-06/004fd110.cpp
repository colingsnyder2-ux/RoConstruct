// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_claude_cylinder_decal_9d1ee56be8d1f428.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include "G3D/Vector2.h"
#include "G3D/Vector3.h"
// from server: 77% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace G3D {
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
struct Dummy1 { Dummy1() {} ~Dummy1(); };
struct Dummy2 { Dummy2() {} ~Dummy2(); };
struct Dummy3 { Dummy3() {} ~Dummy3(); };
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
class CylinderBuilder : public LevelBuilder {
    int sides;
public:
    CylinderBuilder(const G3D::ReferenceCountedPointer<Render::Mesh::Level>& level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes)
        : LevelBuilder(level, size, surfaceTypes), sides(6) {}
    virtual void buildFace(NormalId face, Usage usage);
};
class CylinderAlongXMesh : public Render::Mesh {
public:
    CylinderAlongXMesh(const G3D::Vector3& size, NormalId textureFace);
};
CylinderAlongXMesh::CylinderAlongXMesh(const G3D::Vector3& size, NormalId textureFace)
{
    // The target unwind map has null-action states 1->0, 2->0, 3->2 with the same shape as the live
    // new/level/builder states 4->0, 5->0, 6->5: a compiled-out copy of this block precedes it.
    if (false) {
        G3D::ReferenceCountedPointer<Render::Mesh::Level> level = new Render::Mesh::Level(G3D::RenderDevice::QUADS);
        levels.push_back(level);
        CylinderBuilder builder(level, size, RenderSurfaceTypes());
        builder.buildFace(textureFace, LevelBuilder::Surface);
    }
    G3D::ReferenceCountedPointer<Render::Mesh::Level> level = new Render::Mesh::Level(G3D::RenderDevice::QUADS);
    levels.push_back(level);

    CylinderBuilder builder(level, size, RenderSurfaceTypes());


    builder.buildFace(textureFace, LevelBuilder::Decal);
}
}
}
