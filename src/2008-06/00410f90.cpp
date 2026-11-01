// from server: 100% by king_originala
struct Link {
    void* unused;
    void* previous;
};

struct State {
    void* previous;
    Link* link;
    void* context;
    int active;

    State(void*);
};

struct Input {
    unsigned char reserved[8];
    unsigned short value;
};

extern "C" void* __cdecl get_state();
extern "C" void __stdcall release_state(int, void*);

int __stdcall function(const Input* input, unsigned short* output)
{
    State state(get_state());
    *output = input->value;

    if (state.link)
        state.link->previous = state.previous;

    if (state.active)
        release_state(0, state.context);

    return 0;
}
