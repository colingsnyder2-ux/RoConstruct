// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
template<class T> class Array {
    T* data; int num; int numAllocated;
public:
    Array() { num = 0; numAllocated = 0; data = 0; }
    ~Array();
};
}
namespace boost {
template<class T> class scoped_ptr {
    T* px;
public:
    explicit scoped_ptr(T* p = 0) : px(p) {}
    ~scoped_ptr() { delete px; }
};
}
namespace RBX {
class World; class ContactManager; class Primitive;
class SpatialHash { public: SpatialHash(World* w, ContactManager* cm); ~SpatialHash(); char pad[0xbc]; };
namespace Profiling { class CodeProfiler { public: CodeProfiler(const char* name); ~CodeProfiler(); char pad[0xc040]; }; }
class ContactManager {
    SpatialHash* spatialHash;
    World* world;
    G3D::Array<Primitive*> temp;
    boost::scoped_ptr<Profiling::CodeProfiler> profilingBroadphase;
public:
    ContactManager(World* world);
};
ContactManager::ContactManager(World* world)
    : spatialHash(new SpatialHash(world, this)), world(world),
      profilingBroadphase(new Profiling::CodeProfiler("Broadphase"))
{
}
}
