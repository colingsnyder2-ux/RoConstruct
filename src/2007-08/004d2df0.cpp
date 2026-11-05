// from server: 100% by EspClaude
// roc 2007-08 004d2df0  RBX::Render::Chunk::Chunk(float) (G3D ReferenceCountedObject + WeakReferenceCountedPointer<AggregateChunk>)
#include <limits>

namespace G3D {
inline const double& inf() {
    static const double i = std::numeric_limits<double>::infinity();
    return i;
}
class AtomicInt32 {
    volatile long _value;
public:
    explicit AtomicInt32(const int x) { _value = x; }
};
class ReferenceCountedObject {
public:
    AtomicInt32 ReferenceCountedObject_refCount;
    void* ReferenceCountedObject_weakPointer;
protected:
    ReferenceCountedObject() : ReferenceCountedObject_refCount(0), ReferenceCountedObject_weakPointer(0) {}
public:
    virtual ~ReferenceCountedObject() {}
};
class _WeakPtr {
public:
    virtual ~_WeakPtr() {}
protected:
    virtual void objectCollected() = 0;
};
template<class T> class WeakReferenceCountedPointer : public _WeakPtr {
    T* pointer;
public:
    WeakReferenceCountedPointer() : pointer(0) {}
    ~WeakReferenceCountedPointer();
protected:
    virtual void objectCollected();
};
}

namespace RBX { namespace Render {
class AggregateChunk;
class Chunk : public G3D::ReferenceCountedObject {
    float size;
    float lastTime;
    G3D::WeakReferenceCountedPointer<AggregateChunk> aggregate;
    static int count;
public:
    Chunk(float size);
    ~Chunk();
};

Chunk::Chunk(float size)
    : size(size), lastTime((float)G3D::inf())
{
    ++count;
}
}}
