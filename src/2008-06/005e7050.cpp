// from server: 100% by king_originala
struct Link {
    void assign(Link*);
};

struct State {
    void assign(State*);
    void update(int);
};

struct Source {
    int value();
};

struct Clump {
    char pad0[0x5c];
    Link* link;
    char pad1[0x40];
    State* state;
};

void __cdecl func_005e7050(Clump* first, Source* source, Clump* third)
{
    third->link->assign(first->link);
    third->state->assign(first->state);
    State* state = third->state;
    state->update(source->value());
}
