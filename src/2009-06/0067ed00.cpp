// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
template<class T> class Array {
public:
    T* data; int num; int numAllocated;
    void append(const T& value);
};
}
namespace RBX {
class Primitive;
class World {
public:
    virtual ~World();
    char pad[0x18 - 4];
    G3D::Array<Primitive*> touch;
    G3D::Array<Primitive*> touchOther;
    void onPrimitiveTouched(Primitive* touchP, Primitive* touchOtherP);
};
void World::onPrimitiveTouched(Primitive* touchP, Primitive* touchOtherP)
{
    touch.append(touchP);
    touchOther.append(touchOtherP);
}
}
