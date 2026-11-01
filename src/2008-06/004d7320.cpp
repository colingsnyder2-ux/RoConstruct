// from server: 100% by king_originala
struct Callee
{
    void release(void *);
};

struct State
{
    unsigned char padding[12];
    Callee *first;
    void *second;
};

void __stdcall func_004d7320(State **arg, unsigned int)
{
    State *state = *arg;
    if (state->second != 0)
        state->first->release(state->second);
    state->second = 0;
    state->first = 0;
}
