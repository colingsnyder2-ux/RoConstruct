// from server: 100% by EspClaude
// roc 2008-06 005493e0  unit: seg_00540000  size: 550 bytes
// roc-flags: /Od /GS /EHsc /MD
#include <string>

namespace Ogre {
class Resource {
public:
    __declspec(dllimport) const std::string& getName() const;
};
class Mesh : public Resource {};
class MeshSharedPtr {
protected:
    Mesh* pRep;
    unsigned int* pUseCount;
public:
    virtual ~MeshSharedPtr();
    __declspec(dllimport) bool isNull() const;
    __declspec(dllimport) Mesh* operator->() const;
};
class MeshPtr : public MeshSharedPtr {
public:
    __declspec(dllimport) virtual ~MeshPtr();
    __declspec(dllimport) MeshPtr& operator=(const MeshPtr& r);
};
enum LogMessageLevel { LML_TRIVIAL = 1, LML_NORMAL = 2, LML_CRITICAL = 3 };
class LogManager {
public:
    __declspec(dllimport) static LogManager& getSingleton();
    __declspec(dllimport) void logMessage(const std::string& message, LogMessageLevel lml = LML_NORMAL, bool maskDebug = false);
};
}

struct Vector3 { float x, y, z; };
template <class T> struct Array {
    T* data; int num; int cap;
    int size() const;
    T& operator[](int i);
};
struct ColorArray {
    void* data;
    void* getCArray();
};

class MeshBuilder {
public:
    void build(Ogre::MeshPtr& mesh, Vector3* verts, int numVerts, int* indices, int a, void* colors, int b, int c, int d);
    Ogre::MeshPtr create(const char* name, const char* group, Vector3* verts, int numVerts, int* indices, int a, void* colors, int b, int c, int d);
};

class MeshCache {
public:
    static int state;
    static Ogre::MeshPtr mesh;
    static Array<Vector3> verts;
    static Array<int> indices;
    static ColorArray colors;
    static void update(MeshBuilder* builder);
};
static bool dirty;

void MeshCache::update(MeshBuilder* builder)
{
    if (!dirty)
        return;
    if (!verts.size())
        return;
    if (!mesh.isNull()) {
        builder->build(mesh, &verts[0], verts.size(), &indices[0], 0, colors.getCArray(), 0, 0, 0);
        dirty = false;
    } else if (mesh.isNull()) {
        mesh = builder->create("rbxvb", "General", &verts[0], verts.size(), &indices[0], 0, colors.getCArray(), 0, 0, 0);
        Ogre::LogManager::getSingleton().logMessage(std::string("create mesh=") + mesh->getName() + "\n");
        dirty = false;
        state = 0;
    }
}
