// from server: 100% by king_originala
struct Blob {
    char data[0x30];
};

struct Ball;

struct Graph {
    void attach(Graph* other);
    void apply(const Blob& value);
};

struct Helper {
    Blob compute(Ball* first, Ball* second);
};

struct Owner {
    void update();
};

struct State {
    char pad0[0x14];
    volatile bool dirty14;
    char pad15[0x0b];
    Owner* volatile owner;
    char pad24[0x30];
    volatile bool dirty54;
    char pad55[0x14];
    volatile bool dirty69;
};

struct Ball {
    char pad0[0x5c];
    int field_5c;
    char pad60[0x40];
    Graph* graph;
    void setField(int value);
};

void transfer(Ball* first, Helper* helper, Ball* second)
{
    State* state = reinterpret_cast<State*>(first->field_5c);
    second->setField(first->field_5c);
    second->graph->attach(first->graph);

    state->dirty14 = true;
    state->dirty54 = true;
    state->dirty69 = true;

    Owner* owner = state->owner;
    if (owner)
        owner->update();

    Graph* graph = second->graph;
    graph->apply(helper->compute(first, second));
}
