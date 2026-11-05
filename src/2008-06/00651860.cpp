// from server: 100% by king_originala
extern "C" void __cdecl release(void *);

struct Resource {
    void *pointer;
    __forceinline ~Resource();
};

struct S {
    Resource resource;
    void cleanup();
    __forceinline ~S();
};

__forceinline Resource::~Resource()
{
    release(pointer);
}

__forceinline S::~S()
{
    cleanup();
}

void __stdcall destroy(S *object)
{
    object->~S();
}
