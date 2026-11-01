// from server: 100% by king_originala
extern "C" void* __cdecl get_context();
extern "C" void __cdecl release_storage(void*);
extern "C" void __stdcall release_context(int, void*);

struct Guard
{
    int value;
    int* link;
    void* context;
    int active;

    Guard(void*);
};

struct Temporary
{
    void* storage;
    unsigned char remainder[20];

    void clear();
};

struct Manager
{
    void initialize(Temporary*);
};

extern Manager manager;

int __stdcall function(void*)
{
    Guard guard(get_context());
    Temporary temporary;

    manager.initialize(&temporary);
    temporary.clear();
    release_storage(temporary.storage);

    if (guard.link)
        guard.link[1] = guard.value;

    if (guard.active)
        release_context(0, guard.context);

    return 0;
}
