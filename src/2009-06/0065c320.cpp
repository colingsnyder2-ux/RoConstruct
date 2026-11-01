// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Primitive;
struct Link {
    void set(void*);
};
struct World {
    void attach(Primitive*);
    void detach(Primitive*);
};
struct Provider {
    char padding[0x180];
    char value;
};
struct S {
    char padding[0x9c];
    Link link;
    char padding2[0x118 - 0x9c - sizeof(Link)];
    Primitive* primitive;
    char padding3[0x168 - 0x11c];
    World* world;

    void base(void*);
    void f(void*);
};
extern World* __cdecl findWorld(S*);
extern Provider* __cdecl findProvider(S*);
void S::f(void* arg)
{
    base(arg);
    World* next = findWorld(this);
    if (next != world) {
        if (world) {
            link.set(0);
            world->detach(primitive);
        }
        world = next;
        if (next) {
            next->attach(primitive);
            Provider* provider = findProvider(this);
            link.set(provider ? &provider->value : 0);
        }
    }
}
