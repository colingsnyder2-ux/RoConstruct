// from server: 100% by king_originala
struct State {
    char padding[0xA8];
    unsigned char a;
    unsigned char b;
    unsigned char c;
};

struct Clump {
    char padding[0x1C];
    State* state;
    int f();
};

int Clump::f() {
    return state->a || state->b || state->c;
}
