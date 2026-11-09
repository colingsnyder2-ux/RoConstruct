// from server: 100% by king_originala
struct Value {
    int a, b, c, d, extra;
};

struct Payload {
    int a, b, c, d;
};

extern int marker;
bool __cdecl func_0060a2f0();

struct S {
    int* state;
    int reserved;
    Payload payload;

    S(Value value);
};

S::S(Value value)
{
    state = 0;
    if (!reinterpret_cast<bool (__cdecl *)(const Value*)>(
            func_0060a2f0)(&value)) {
        Payload* destination = &payload;
        if (destination) {
            destination->a = value.a;
            destination->b = value.b;
            destination->c = value.c;
            destination->d = value.d;
        }
        state = &marker;
    } else {
        state = 0;
    }
}
