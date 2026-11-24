// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: the OgreMeshManager.h include is dropped because it is not under native-headers. This file declares minimal Ogre types itself. Their layouts come from the disassembly and Ogre 1.4.
namespace Ogre {
struct Vector3 {
    float x, y, z;
    Vector3() {}
    static const Vector3 UNIT_X, UNIT_Y, UNIT_Z;
    Vector3 operator-() const { Vector3 r = { -x, -y, -z }; return r; }
};
struct Plane {
    Vector3 normal;
    float d;
    __declspec(dllimport) Plane();
};
struct Quaternion {
    float w, x, y, z;
    __declspec(dllimport) Vector3 operator*(const Vector3& v) const;
};
struct Resource {
    char pad[0x5c];
    unsigned long handle; // INFERRED: handle at +0x5c
};
struct MeshPtr {
    // INFERRED: SharedPtr layout from the disassembly: vtable, pRep at +4, use count ptr at +8
    virtual ~MeshPtr();
    Resource* pRep;
    unsigned int* pUseCount;
    __declspec(dllimport) MeshPtr(const MeshPtr&);
    __declspec(dllimport) MeshPtr& operator=(const MeshPtr&);
    bool isNull() const { return pRep == 0; }
};
struct MeshManager {
    __declspec(dllimport) static MeshManager& getSingleton();
    // INFERRED: vtable slot 0x3c is remove(handle), slot 0x4c is getByName
    virtual void v0();  virtual void v1();  virtual void v2();  virtual void v3();
    virtual void v4();  virtual void v5();  virtual void v6();  virtual void v7();
    virtual void v8();  virtual void v9();  virtual void v10(); virtual void v11();
    virtual void v12();  virtual void v13(); virtual void v14();
    virtual void remove(unsigned long handle);       // slot 0x3c
    virtual void v16();  virtual void v17(); virtual void v18();
    virtual MeshPtr getByName(const std::string& name); // slot 0x4c
    __declspec(dllimport) MeshPtr createPlane(const std::string& name, const std::string& group,
        const Plane& plane, float width, float height, int xseg, int yseg, bool normals,
        int numTexCoordSets, float utile, float vtile, const Vector3& upVector,
        int vbUsage, int ibUsage, bool vbShadow, bool ibShadow);
};
}

// INFERRED: 'this' holds the sky name string at +4. Arg 1 is the MeshPtr result, which also serves as the hidden return.
struct SkyBoxHolder {
    int pad;
    std::string name;
};

extern "C" Ogre::MeshPtr* __fastcall fn_0068efd0(SkyBoxHolder* self, int unusedEdx,
    Ogre::MeshPtr* result, int face, float dist, const Ogre::Quaternion* orient,
    const std::string& group)
{
    Ogre::Plane plane;
    std::string planeName;
    planeName = std::string("SkyBoxPlane_") + self->name;
    Ogre::Vector3 up;

    switch (face) {
    case 0: planeName += "Front"; plane.normal = Ogre::Vector3::UNIT_Z;  up = Ogre::Vector3::UNIT_Y; break;
    case 1: planeName += "Back";  plane.normal = -Ogre::Vector3::UNIT_Z; up = Ogre::Vector3::UNIT_Y; break;
    case 2: planeName += "Left";  plane.normal = Ogre::Vector3::UNIT_X;  up = Ogre::Vector3::UNIT_Y; break;
    case 3: planeName += "Right"; plane.normal = -Ogre::Vector3::UNIT_X; up = Ogre::Vector3::UNIT_Y; break;
    case 4: planeName += "Up";    plane.normal = -Ogre::Vector3::UNIT_Y; up = Ogre::Vector3::UNIT_Z; break;
    case 5: planeName += "Down";  plane.normal = Ogre::Vector3::UNIT_Y;  up = -Ogre::Vector3::UNIT_Z; break;
    }
    plane.d = dist;

    plane.normal = (*orient) * plane.normal;
    up = (*orient) * up;

    Ogre::MeshManager& mm = Ogre::MeshManager::getSingleton();
    new (result) Ogre::MeshPtr(mm.getByName(planeName));
    if (!result->isNull())
        mm.remove(result->pRep->handle);

    *result = mm.createPlane(planeName, group, plane, dist * 2.0f, dist * 2.0f,
        1, 1, true, 1, 1.0f, 1.0f, up, 5, 5, true, true);
    return result;
}
