// from server: 100% by king_originala
struct State {
    unsigned first;
    unsigned reserved[2];
    unsigned current;
    unsigned limit;
};

struct Result {
    unsigned first;
    unsigned current;
};

extern State* __cdecl getState();
extern "C" void (__cdecl* _invalid_parameter_noinfo)();

Result* __cdecl f(Result* volatile result)
{
    State* state = getState();
    unsigned current = state->current;
    if (current > state->limit)
        _invalid_parameter_noinfo();

    Result* output = result;
    unsigned first = state->first;
    output->current = current;
    output->first = first;
    return output;
}
