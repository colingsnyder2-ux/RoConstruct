// from server: 100% by king_originala
struct Target {
    void release();
};

struct State {
    bool ready();
    Target** current();
    void advance();
};

void __stdcall process(void* object)
{
    State* state = reinterpret_cast<State*>(
        static_cast<char*>(object) + 0xEC);

    if (state->ready()) {
        (*state->current())->release();
        state->advance();
    }
}
