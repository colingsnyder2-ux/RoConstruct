// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O1 /GS- /EHsc /MD
struct State {
    char padding[0x104];
    bool enabled;
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

bool toggleIDEModeEnabled()
{
    return !getRoot()->context->state->enabled;
}
