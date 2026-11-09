// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class System { public: static void alignedFree(void* ptr); };
class Vector3 {
public:
    float x, y, z;
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    static const Vector3& zero() { static Vector3 v(0, 0, 0); return v; }
};
template <class T>
class Array {
private:
    T* data;
    int num;
    int numAllocated;
    void resize(int n);
    void init(int n, int a) {
        this->num = 0;
        this->numAllocated = 0;
        data = 0;
        if (a > 0) {
            resize(n);
        } else {
            data = 0;
        }
    }
public:
    Array() { init(0, 0); }
    ~Array() { System::alignedFree(data); }
    void append(const T& value);
};
}
namespace RBX {
class Primitive { char pad[4]; };
class ContactManager;
class World {
    char pad[0x84];
    ContactManager* contactManager;
public:
    ContactManager* getContactManager() { return contactManager; }
};
class Instance;
class Workspace { public: static World* getWorldIfInWorkspace(Instance* instance); };
class Dragger { public: static G3D::Vector3 safeMoveNoDrop(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& tryDrag, ContactManager& contactManager); };
class PartInstance {
    char pad[0x228];
    Primitive primitive;
public:
    void safeMove();
};
void PartInstance::safeMove()
{
    if (World* world = Workspace::getWorldIfInWorkspace((Instance*)this)) {
        G3D::Array<Primitive*> temp;
        temp.append(&primitive);
        Dragger::safeMoveNoDrop(temp, G3D::Vector3::zero(), *world->getContactManager());
    }
}
}
