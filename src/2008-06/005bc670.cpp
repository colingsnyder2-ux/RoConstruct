// from server: 100% by king_originala
struct Resource {
    char padding[8];
    int references;
};

struct ResourcePair {
    Resource* pointer;
    void* control;
    void clear();
};

extern "C" int __stdcall releaseHandle(void* handle, int flags);
extern "C" void __cdecl checkResult(int result);

struct S {
    char padding[0x134];
    ResourcePair resource;
    void* handle;

    void cleanup();
    void f();
};

void S::f()
{
    if (handle) {
        checkResult(releaseHandle(handle, 0));
        handle = 0;
    }

    if (resource.pointer) {
        --resource.pointer->references;
        resource.clear();
    }

    cleanup();
}
