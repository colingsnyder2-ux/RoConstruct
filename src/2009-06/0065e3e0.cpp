// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    static const Vector3& zero() { static Vector3 v; return v; }
};
namespace System { void alignedFree(void*); }
template<class T> class Array {
public:
    T* data;
    int num;
    int numAllocated;
    Array() { num = 0; numAllocated = 0; data = 0; }
    ~Array() {
        System::alignedFree(data);
        data = 0;
        num = 0;
        numAllocated = 0;
    }
    void append(const T& value);
};
}
namespace RBX {
class Primitive;
class ContactManager;
class World {
public:
    char pad[0xb0];
    ContactManager* contactManager;
    ContactManager* getContactManager() { return contactManager; }
};
class PartInstance;
class Workspace { public: static World* getWorldIfInWorkspace(PartInstance*); };
class Dragger {
public:
    static G3D::Vector3 safeMoveNoDrop(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& tryDrag, ContactManager& contactManager);
};
template<class T> class scoped_ptr { public: T* px; T* get() const { return px; } };
class PartInstance {
private:
    void safeMove();
public:
    char pad[0x118];
    scoped_ptr<Primitive> primitive;
};
void PartInstance::safeMove()
{
    if (World* world = Workspace::getWorldIfInWorkspace(this)) {
        G3D::Array<Primitive*> temp;
        temp.append(primitive.get());
        Dragger::safeMoveNoDrop(temp, G3D::Vector3::zero(), *world->getContactManager());
    }
}
}
