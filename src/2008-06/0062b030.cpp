// from server: 100% by king_originala
struct Listener {
    void attach(Listener*);
    void detach(Listener*);
};

struct World {
    char padding[0x150];
    Listener listeners;
};

struct Instance {
    World* resolve();
};

struct Prefix {
    char padding[0x130];
};

struct Explosion : Prefix, Listener {
    void change(Instance*, Instance*);
};

void Explosion::change(Instance* oldInstance, Instance* newInstance)
{
    Listener* oldListener = static_cast<Listener*>(this);
    if (oldInstance) {
        World* world = oldInstance->resolve();
        if (world)
            world->listeners.attach(oldListener);
    }

    Listener* newListener = static_cast<Listener*>(this);
    if (newInstance) {
        World* world = newInstance->resolve();
        if (world)
            world->listeners.detach(newListener);
    }
}
