// from server: 100% by king_originala
struct Component {
    char padding[0xfc];
    void set(void*);
};

struct Link {
    char padding[0x68];
    void set(void*);
};

struct Owner {
    void attach(Component*);
    void detach(Component*);
};

struct Provider {
    char padding[0x314];
    char value;
};

struct S {
    char padding[0x1c0];
    Link link;
    Component component;
    Owner* owner;

    void base(void*);
    void* getValue();
    void f(void*);
};

extern Owner* __cdecl findOwner(S*);
extern Provider* __cdecl findProvider(S*);

void S::f(void* arg)
{
    base(arg);
    Owner* next = findOwner(this);
    if (next != owner) {
        if (owner) {
            link.set(0);
            owner->detach(&component);
        }
        owner = next;
        if (next) {
            next->attach(&component);
            Provider* provider = findProvider(this);
            link.set(provider ? &provider->value : 0);
            component.set(getValue());
        }
    }
}
