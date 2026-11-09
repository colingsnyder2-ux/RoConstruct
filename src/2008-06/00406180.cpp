// from server: 100% by king_originala
extern "C" unsigned int __cdecl get_context();
extern "C" void __stdcall release_context(unsigned int, void *);

struct Link {
    unsigned int reserved;
    Link *previous;
};

struct Context {
    Link *saved;
    Link *current;
    void *handle;
    unsigned int active;

    Context(unsigned int);
};

struct State {
    unsigned char query();
};

extern State global_state;

int __stdcall function(void *, short *result)
{
    Context context(get_context());

    *result = global_state.query() ? -1 : 0;

    if (context.current)
        context.current->previous = context.saved;

    if (context.active)
        release_context(0, context.handle);

    return 0;
}
