// from server: 26% by atomic.potato
extern "C" void* __stdcall allocBytes(unsigned int size, const char* file, int line, const char* func);

struct RbxSceneManager {
    void construct(void* arg);
};

struct Factory {
    RbxSceneManager* create(void* arg);
};

RbxSceneManager* Factory::create(void* arg)
{
    RbxSceneManager* p = (RbxSceneManager*)allocBytes(0x4810, "QVW3", 0, 0);
    if (p) {
        p->construct(arg);
    }
    return p;
}
