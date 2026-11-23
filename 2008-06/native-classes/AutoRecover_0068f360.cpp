// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: Ogre SceneManager::_setSkyDomePlane analog. 'self' has a std::string name at +4.
// INFERRED: The Ogre headers are not on the include path (OgreMesh.h was not found).
// So this file declares minimal Ogre stand-ins in namespace Ogre, so the imports keep their mangled names.
#include <string>

namespace Ogre {
struct Vector3 {
    float x, y, z;
    static const Vector3 UNIT_X, UNIT_Y, UNIT_Z;
};
struct Quaternion {
    float w, x, y, z;
    Vector3 operator*(const Vector3& v) const;
};
struct Plane {
    Vector3 normal;
    float d;
    Plane();
};
struct Resource {
    virtual ~Resource();
    virtual void destroy();
    char pad[0x54];
    unsigned long handle; // +0x5c
};
template <class T> struct SharedPtr {
    T* pRep;
    unsigned int* pUseCount;
};
struct Mesh;
struct MeshPtr {
    MeshPtr();
    MeshPtr(const MeshPtr&);
    MeshPtr(const SharedPtr<Resource>&);
    MeshPtr& operator=(const MeshPtr&);
    virtual ~MeshPtr();
    Resource* pRep;
    unsigned int* pUseCount;
};
struct HardwareBuffer {
    enum Usage { HBU_STATIC_WRITE_ONLY = 5, HBU_DYNAMIC_WRITE_ONLY = 6 };
};
struct MeshManager {
    static MeshManager& getSingleton();
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void remove(unsigned long handle); // slot 0x3c
    virtual SharedPtr<Resource> getByName(const std::string& name); // slot 0x4c
    MeshPtr createCurvedIllusionPlane(const std::string& name, const std::string& group,
        const Plane& plane, float width, float height, float curvature,
        int xsegments, int ysegments, bool normals, unsigned short numTexCoordSets,
        float xTile, float yTile, const Vector3& upVector, const Quaternion& orientation,
        HardwareBuffer::Usage vbUsage, HardwareBuffer::Usage ibUsage,
        bool vbShadow, bool ibShadow, int ySegmentsToKeep);
};
}

using namespace Ogre;

struct SkyDomeHost {
    int vtbl;
    std::string name; // +4
};

extern "C" MeshPtr* __fastcall fn_0068f360(SkyDomeHost* self, int unusedEdx, MeshPtr* out, int bp,
    float curvature, float tiling, float distance, const Quaternion& orientation,
    int xsegments, int ysegments, int ySegmentsToKeep, const std::string& groupName)
{
    Plane plane;
    std::string meshName;
    meshName = self->name + "SkyDomePlane_";
    plane.d = distance;
    Vector3 up;
    switch (bp) {
    case 0: meshName += "Front"; plane.normal = Vector3::UNIT_Z; up = Vector3::UNIT_Y; break;
    case 1: meshName += "Back";
        plane.normal.x = -Vector3::UNIT_Z.x; plane.normal.y = -Vector3::UNIT_Z.y; plane.normal.z = -Vector3::UNIT_Z.z;
        up = Vector3::UNIT_Y; break;
    case 2: meshName += "Left"; plane.normal = Vector3::UNIT_X; up = Vector3::UNIT_Y; break;
    case 3: meshName += "Right";
        plane.normal.x = -Vector3::UNIT_X.x; plane.normal.y = -Vector3::UNIT_X.y; plane.normal.z = -Vector3::UNIT_X.z;
        up = Vector3::UNIT_Y; break;
    case 4: meshName += "Up";
        plane.normal.x = -Vector3::UNIT_Y.x; plane.normal.y = -Vector3::UNIT_Y.y; plane.normal.z = -Vector3::UNIT_Y.z;
        up = Vector3::UNIT_Z; break;
    default:
        new (out) MeshPtr();
        return out;
    }
    plane.normal = orientation * plane.normal;
    up = orientation * up;
    MeshManager& mm = MeshManager::getSingleton();
    {
        MeshPtr old(mm.getByName(meshName));
        if (old.pRep)
            mm.remove(old.pRep->handle);
    }
    MeshPtr m;
    m = mm.createCurvedIllusionPlane(meshName, groupName, plane,
        distance * 2.0f, distance * 2.0f, curvature, xsegments, ysegments,
        true, 1, tiling, tiling, up, orientation,
        HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, HardwareBuffer::HBU_STATIC_WRITE_ONLY,
        true, true, ySegmentsToKeep);
    new (out) MeshPtr(m);
    return out;
}
