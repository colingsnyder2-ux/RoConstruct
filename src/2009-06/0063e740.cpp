// from server: 91% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast

#define NULL 0
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    Vector3(const Vector3& V) : x(V.x), y(V.y), z(V.z) {}
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
    Vector3 operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
    Vector3 operator-() const { return Vector3(-x, -y, -z); }
};
class Matrix3 {
public:
    float elt[3][3];
    Vector3 getColumn(int iCol) const;
};
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    static const float zLookDirection;
    Vector3 lookVector() const { return rotation.getColumn(2) * zLookDirection; }
};
}

namespace boost {
template<class T> class shared_ptr {
public:
    T* px;
    void* pn;
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
    T* operator->() const { return px; }
    void reset();
};
}

namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad0[0x44];
    Instance* parent;
    char pad1[0x8c - 0x4c];
    Instance* getParent() const { return parent; }
    void setParent(Instance* p);
};
class ExePad4 { public: virtual void exePad4(); };
class IHasLocation { public: virtual const G3D::CoordinateFrame getLocation() = 0; };
class ModelInstance : public Instance, public ExePad4, public virtual IHasLocation {};
class PartInstance : public Instance {
public:
    void setCanCollide(bool);
    void moveToPoint(G3D::Vector3);
    void setRotationalVelocity(const G3D::Vector3&);
};
class JointInstance : public Instance {
public:
    PartInstance* getPart0();
};
class Humanoid {
public:
    static Humanoid* modelIsCharacter(Instance*);
};
class IExeListener { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void setValue(float); };
class Tool : public Instance {
public:
    int exePad8c;
    boost::shared_ptr<JointInstance> weld;
    char pad98[0xac - 0x98];
    IExeListener listener;
    PartInstance* getHandle();
    void onUnequipped();
    void downFrom_Equipped();
};

void Tool::downFrom_Equipped()
{
    ModelInstance* character = NULL;
    if (weld)
    {
        if (PartInstance* part0 = weld->getPart0())
            character = dynamic_cast<ModelInstance*>(part0->getParent());
        weld->setParent(NULL);
        weld.reset();
    }

    if (Humanoid::modelIsCharacter(character))
    {
        G3D::CoordinateFrame location = character->getLocation();
        G3D::Vector3 pos = location.translation;
        pos.y += 4;
        G3D::Vector3 dest = location.lookVector() * 8 + pos;
        if (PartInstance* handle = getHandle())
        {
            handle->setCanCollide(true);
            handle->moveToPoint(dest);
            handle->setRotationalVelocity(G3D::Vector3(1, 1, 1));
        }
    }

    listener.setValue(999.0f);
    onUnequipped();
}
}
