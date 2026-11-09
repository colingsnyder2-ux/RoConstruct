// from server: 100% by king_originala
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

struct Object
{
    void update();
};

extern "C" void* __stdcall getState();
extern "C" void __stdcall releaseState(int, void*);

int __stdcall function(Object* object)
{
    StateGuard guard;
    guard.initialize(getState());
    object->update();

    if (guard.slot)
        guard.slot->value = guard.previous;

    if (guard.active)
        releaseState(0, guard.context);

    return 0;
}
