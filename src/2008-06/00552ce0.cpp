// from server: 55% by king_originala
struct Pair {
    unsigned int first;
    unsigned int second;
    Pair();
};

struct Functor {
    unsigned int state[4];
};

extern Pair __cdecl transform(Pair value);
extern Pair __cdecl advance(Pair value, Functor operation);

struct Container {
    Pair firstOperation(Pair value);
    Pair secondOperation(Pair value);
};

struct S {
    unsigned char padding[8];
    Container container;
    Container* f(const Pair* value);
};

#pragma optimize("", off)
Container* S::f(const Pair* value)
{
    Functor operation;
    Pair end;
    unsigned int index;
    Pair current = *value;

    for (index = 0; current.first; current.first = current.second) {
        advance(
            container.secondOperation(
                container.firstOperation(
                    transform(current))),
            operation);
    }
    return &container;
}
