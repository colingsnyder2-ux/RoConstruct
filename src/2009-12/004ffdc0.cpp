// from server: 32% by atomic.potato
typedef unsigned long DWORD;

extern "C" void Invoke(void*, DWORD);
extern "C" void __cdecl ConstructString(void*, const char*);
extern void* g_string_allocator;

struct S
{
    int f(void*, void*);
};

int S::f(void* a, void* b)
{
    void* p = *(void**)this;
    void (__cdecl *v)(void*, DWORD) =
        (void (__cdecl *)(void*, DWORD))(*(DWORD*)((char*)p + 0x1c));
    v(this, 0);

    ConstructString(b, ">Authoring");
    return 0;
}
