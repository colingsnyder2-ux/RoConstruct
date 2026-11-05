// from server: 100% by king_originala
struct State {
    char pad[48];
    bool enabled;
};

struct Object {
    char pad[712];
    State* state;
};

struct Provider {
    Object* getA();
    Object* getB();
    Object* getC();
    Object* getD();
    Object* getE();
    Object* getF();
};

struct ScriptMouseCommand {
    char pad[8];
    Provider* provider;
    void f(bool enabled);
};

void ScriptMouseCommand::f(bool enabled)
{
    if (provider) {
        if (provider->getA())
            provider->getA()->state->enabled = enabled;
        if (provider->getB())
            provider->getB()->state->enabled = enabled;
        if (provider->getF())
            provider->getF()->state->enabled = enabled;
        if (provider->getE())
            provider->getE()->state->enabled = enabled;
        if (provider->getD())
            provider->getD()->state->enabled = enabled;
        if (provider->getC())
            provider->getC()->state->enabled = enabled;
    }
}
