// from server: 100% by king_originala
struct State {
    char padding[28];
    int active;
};

struct Link {
    void* first;
    void* second;
};

struct Guard {
    void* saved;
    Link* link;
    void* resource;
    int cleanup;

    void acquire(void*);
};

extern State** globalState;
extern "C" void* __cdecl getResource();
extern "C" void __stdcall releaseResource(int, void*);

struct S {
    int f(int unused, short* result);
};

int S::f(int unused, short* result)
{
    Guard guard;
    guard.acquire(getResource());

    *result = (*globalState)->active ? -1 : 0;

    if (guard.link)
        guard.link->second = guard.saved;

    if (guard.cleanup)
        releaseResource(0, guard.resource);

    return 0;
}
