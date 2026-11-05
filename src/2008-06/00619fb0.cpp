// from server: 100% by king_originala
struct Receiver
{
    void begin();
    void end();
};

struct State
{
    Receiver* receiver;
    void reset();
    void set(int value);
};

struct Instance;

struct ServiceProvider
{
    void set(int value);
};

extern ServiceProvider* __cdecl findProvider(Instance* instance);

struct WeldTool
{
    char padding[0x18];
    Instance* instance;
    void apply(State* state);
};

void WeldTool::apply(State* state)
{
    state->receiver->begin();
    state->reset();
    state->set(2);
    state->receiver->end();
    findProvider(instance)->set(8);
}
