// from server: 100% by colin
// from server: 93% by atomic.potato
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
struct State {
    char padding[0x1c0];
    float divisor;
    char gap[4];
    double first;
    double second;
    double third;
};

struct S {
    char padding[0x20c];
    State* state;
    double f();
};

double S::f() {
    return (state->third + state->second + state->first) *
           (1.0 / state->divisor);
}
