// from server: 100% by king_originala
struct ThreadState {
    void* reserved;
    void* current;
};

struct StateGuard {
    void* previous;
    ThreadState* thread;
    void* context;
    int active;

    StateGuard(void*);
};

extern "C" void* __cdecl get_state();
extern "C" void* __cdecl get_type_info(int);
extern "C" void __stdcall release_state(int, void*);

long __stdcall get_info(unsigned int, unsigned long, void** result)
{
    StateGuard guard(get_state());

    if (result)
        *result = get_type_info(0);

    if (guard.thread)
        guard.thread->current = guard.previous;

    if (guard.active)
        release_state(0, guard.context);

    return (long)0x80004001;
}
