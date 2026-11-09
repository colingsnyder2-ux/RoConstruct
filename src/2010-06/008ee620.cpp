// from server: 44% by atomic.potato
struct RbxMeshPartAdapter {
    void fillVertices(int);
};

struct MeshManager {
    static MeshManager& getSingleton();
    void load(const char*, const char*);
};

extern "C" unsigned int __stdcall RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS;

struct Ptr {
    void* p;
    Ptr();
    ~Ptr();
};

void RbxMeshPartAdapter::fillVertices(int a)
{
    Ptr local;
    MeshManager& mm = MeshManager::getSingleton();
    mm.load("textures\\nosurfacesTruss.png", (const char*)a);
    if (RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS == 0) {
        MeshManager::getSingleton().load("textures\\nosurfacesTruss.png", (const char*)a);
    }
}
