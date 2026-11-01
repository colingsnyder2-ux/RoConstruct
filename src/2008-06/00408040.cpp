// from server: 100% by king_originala
extern "C" void* __cdecl get_context();
extern "C" void* __cdecl get_object();
extern "C" void __stdcall release_context(int, void*);

struct ContextGuard
{
    int saved;
    int* slot;
    void* handle;
    int active;

    void initialize(void*);
};

int __stdcall get_value(void*, int* result)
{
    ContextGuard guard;
    guard.initialize(get_context());

    *result = *(int*)((char*)get_object() + 0x134);

    if (guard.slot)
        guard.slot[1] = guard.saved;

    if (guard.active)
        release_context(0, guard.handle);

    return 0;
}
