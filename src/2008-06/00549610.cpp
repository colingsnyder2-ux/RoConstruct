// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Local names were chosen to reproduce the /Od frame layout (MSVC orders locals by name hash).
// Analog for 00549610 (NativeMeshLevel::makeHWSubMesh): expands quads to
// triangles when needed, creates the hardware submesh (0067c020) in the shared
// mesh 009738b8 and computes the level's bounds from the slot positions.
#include <string>

namespace Ogre {
enum LogMessageLevel { LML_TRIVIAL = 1, LML_NORMAL = 2, LML_CRITICAL = 3 };
class LogManager {
public:
    __declspec(dllimport) static LogManager& getSingleton();
    __declspec(dllimport) void logMessage(const std::string& message, LogMessageLevel lml = LML_NORMAL, bool maskDebug = false);
};
class SubMesh;
class Mesh {
public:
    __declspec(dllimport) unsigned short getNumSubMeshes() const;
};
template<class T>
class SharedPtr {
public:
    __declspec(dllimport) T* operator->() const;
    T* pointer;
};
class AxisAlignedBox {
public:
    __declspec(dllimport) void setExtents(float mx, float my, float mz, float Mx, float My, float Mz);
};
class VisualEngine {
public:
    SubMesh* createSubMesh(SharedPtr<Mesh>* mesh, int vertexStart, const int* indices, unsigned triangles);
};
}

class Vec3 {
public:
    float& operator[](int i);
    float x, y, z;
};

template<class T>
class Array {
public:
    int size() const;
    T& operator[](int n);
    T* data;
    int num;
    int numAllocated;
};

template<class T>
class Vector {
public:
    Vector();
    ~Vector();
    void resize(unsigned n);
    T& operator[](unsigned n);
    unsigned size() const;
    int data[0x10 / 4];
};

struct Extent { float x, y, z; };

extern Ogre::SharedPtr<Ogre::Mesh> sharedMesh;
extern Array<Vec3> slotFirst;

class NativeMeshLevel {
public:
    void makeHWSubMesh(Ogre::VisualEngine* engine, Ogre::AxisAlignedBox& bounds);
    int header[0x0c / 4];
    Array<int> source;
    int type;
    bool dirty;
    int index;
};

void NativeMeshLevel::makeHWSubMesh(Ogre::VisualEngine* engine, Ogre::AxisAlignedBox& bounds)
{
    if (dirty) {
        int v354;
        int v322;
        Vector<int> v332;
        Ogre::SubMesh* v358;
        if (type == 5) {
            v332.resize(source.size() / 4 * 6);
            for (int v350 = 0; v350 < source.size(); v350 += 4) {
                int v288 = v350 / 4;
                v332[v288 * 6] = source[v288 * 4];
                v332[v288 * 6 + 1] = source[v288 * 4 + 1];
                v332[v288 * 6 + 2] = source[v288 * 4 + 3];
                v332[v288 * 6 + 3] = source[v288 * 4 + 3];
                v332[v288 * 6 + 4] = source[v288 * 4 + 1];
                v332[v288 * 6 + 5] = source[v288 * 4 + 2];
            }
            v358 = engine->createSubMesh(&sharedMesh, 0, &v332[0], v332.size() / 3);
        } else {
            v358 = engine->createSubMesh(&sharedMesh, 0, &source[0], source.size() / 3);
        }
        if (v358) {
            index = sharedMesh->getNumSubMeshes() - 1;
            dirty = false;
        }
        Extent v292;
        v292.x = 1e9f;
        v292.y = 1e9f;
        v292.z = 1e9f;
        Extent v296;
        v296.x = -1e9f;
        v296.y = -1e9f;
        v296.z = -1e9f;
        float* v362 = &slotFirst[0][0];
        for (int v309 = 0; v309 < source.size(); ++v309) {
            int v284 = source[v309] * 3;
            if (v292.x > v362[v284]) v292.x = v362[v284];
            if (v292.y > v362[v284 + 1]) v292.y = v362[v284 + 1];
            if (v292.z > v362[v284 + 2]) v292.z = v362[v284 + 2];
            if (v296.x < v362[v284]) v296.x = v362[v284];
            if (v296.y < v362[v284 + 1]) v296.y = v362[v284 + 1];
            if (v296.z < v362[v284 + 2]) v296.z = v362[v284 + 2];
        }
        bounds.setExtents(v292.x, v292.y, v292.z, v296.x, v296.y, v296.z);
    } else {
        Ogre::LogManager::getSingleton().logMessage("RBX makeHWSubMesh: should not be here");
    }
}
