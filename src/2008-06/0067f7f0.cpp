// from server: 100% by king_originala
struct ColourValue {
    float r, g, b, a;
};

struct Viewport;

typedef void (__thiscall *SetBackgroundColour)(
    Viewport *, const ColourValue &);

extern SetBackgroundColour setBackgroundColour;

struct Context {
    char padding[16];
    Viewport *viewport;
};

struct Input {
    char padding[12];
    float r, g, b;
};

struct S {
    char padding[184];
    unsigned char enabled;

    void f(Context *, Input *);
    void first(Context *, Input *);
    void second(Context *, Input *);
};

void S::f(Context *context, Input *input)
{
    ColourValue colour = { input->r, input->g, input->b, 1.0f };
    setBackgroundColour(context->viewport, colour);

    if (enabled) {
        first(context, input);
        second(context, input);
    }
}
