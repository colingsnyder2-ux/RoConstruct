// from server: 100% by king_originala
struct Pair {
    int first;
    int second;
};

struct Cache {
    Pair get();
};

struct Container {
    char padding[0x2a8];
    Cache cache;
};

struct Owner {
    char padding[0x204];
    Container* container;
};

struct S {
    char padding[0x15c];
    Owner* owner;
    int index;

    bool f();
};

bool S::f()
{
    Pair temporary = owner->container->cache.get();
    Pair value = temporary;
    return reinterpret_cast<bool*>(&value)[index];
}
