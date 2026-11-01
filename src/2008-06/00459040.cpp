// from server: 100% by colin
extern double delay;
extern double __cdecl getTime();
struct State {
    char padding[0x105];
    unsigned char active;
};
struct Context {
    char padding[0x20];
    State* state;
};
struct Root {
    char padding[4];
    Context* context;
};
extern Root* __cdecl getRoot();
struct ToggleIDEModeVerb {
    char padding[0x10];
    double timestamp;
    bool isEnabled();
};
bool ToggleIDEModeVerb::isEnabled()
{
    double now = getTime();
    if (timestamp + delay > now)
        return false;
    State* s = getRoot()->context->state; return s->active == 0;
}
