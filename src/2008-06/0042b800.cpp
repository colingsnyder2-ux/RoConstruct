// from server: 100% by king_originala
struct Triple {
    unsigned int a, b, c;
};

extern "C" bool __cdecl func_0060a2f0(...);

struct EventHandler {
    void* state;
    unsigned int reserved;
    Triple payload;

    EventHandler* attach(Triple value, unsigned int unused);
};

EventHandler* EventHandler::attach(Triple value, unsigned int unused)
{
    Triple local = value;
    state = 0;

    if (!func_0060a2f0(&local)) {
        Triple* destination = &payload;
        if (destination)
            *destination = local;
        state = reinterpret_cast<void*>(0x810618);
        return this;
    }

    state = 0;
    return this;
}
