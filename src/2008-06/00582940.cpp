// from server: 100% by king_originala
struct Item {
    unsigned data[2];
};

struct Selection {
    char padding[12];
    Item* first;
    Item* last;
};

struct Context {
    char padding[0x154];
    Selection* selection;
};

struct Resolver {
    Context* get();
};

struct Handle {
    char padding[12];
    Resolver* resolver;
    Context* get(int);
};

struct S {
    char padding[0x14];
    Handle handle;
    bool f();
};

bool S::f()
{
    Selection* selection = handle.get(1)->selection;
    if (static_cast<unsigned>(selection->last - selection->first) <= 0)
        return false;

    Context* context = handle.resolver ? handle.resolver->get() : 0;
    selection = context->selection;
    return static_cast<unsigned>(selection->last - selection->first) > 0;
}
