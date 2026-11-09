// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

struct StateSlot
{
    unsigned long reserved;
    void* value;
};

struct StateGuard
{
    void* previous;
    StateSlot* slot;
    void* context;
    int active;

    void initialize(void*);
};

extern "C" void* __stdcall getState();
extern "C" void __stdcall releaseState(int, void*);
extern "C" void __cdecl updateApplication();

int __stdcall roc_vcapp_guarded_call(void*)
{
    StateGuard guard;
    guard.initialize(getState());
    updateApplication();

    if (guard.slot)
        guard.slot->value = guard.previous;

    if (guard.active)
        releaseState(0, guard.context);

    return 0;
}
