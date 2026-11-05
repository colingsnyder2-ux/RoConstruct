// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_rbx_create_indices_0cb0c310d58dd691.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>

struct Mutex {
    int value;
    unsigned char flag;
    int count;
    void acquire();
    void f();
};

struct GlobalState {
    char padding[36];
    Mutex mutex;
};

extern GlobalState *globalState;
extern int initializationFlag;
extern void __cdecl initializeCallback();
extern void __cdecl initialize(void (__cdecl *)(), int *);

struct ScopedLock {
    Mutex *mutex;
    bool held;
    ScopedLock(Mutex *);
    ~ScopedLock();
};

inline ScopedLock::ScopedLock(Mutex *p) : mutex(p), held(false)
{
    mutex->acquire();
    held = true;
}

inline ScopedLock::~ScopedLock()
{
    if (held)
        mutex->f();
}

using namespace Ogre;

SubMesh *__stdcall createIndices(
    const MeshPtr &mesh,
    const void *indices16,
    const void *indices32,
    unsigned int triangles)
{
    initialize(initializeCallback, &initializationFlag);
    ScopedLock lock(&globalState->mutex);

    SubMesh *submesh = mesh->createSubMesh();
    size_t count = triangles * 3;

    HardwareIndexBufferSharedPtr buffer =
        HardwareBufferManager::getSingleton().createIndexBuffer(
            indices16 ? HardwareIndexBuffer::IT_16BIT : HardwareIndexBuffer::IT_32BIT,
            count, HardwareBuffer::HBU_STATIC_WRITE_ONLY);

    buffer->writeData(0, buffer->getSizeInBytes(), indices16 ? indices16 : indices32, true);
    submesh->useSharedVertices = true;
    submesh->indexData->indexBuffer = buffer;
    submesh->indexData->indexCount = count;
    submesh->indexData->indexStart = 0;
    return submesh;
}
