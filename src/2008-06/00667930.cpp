// from server: 100% by king_originala
struct Value {
    void set(float);
};

struct Owner {
    char padding[20];
    char identity;
    Value* first();
    Value* second();
};

struct Signal {
    void notify(const char&, int);
};

struct Entry {
    char padding[16];
    Signal signal;
};

struct Registry {
    Entry* find(void*);
};

extern Registry registry;

struct Base {
    virtual ~Base();
    Owner* owner();
};

struct Interface {
    virtual void interfaceMethod();
};

struct Freefall : Base, Interface {
    char padding[164];
    float savedSecond;
    float savedFirst;

    ~Freefall();
};

Freefall::~Freefall()
{
    Owner* p = owner();
    Entry* entry = registry.find(p ? &p->identity : 0);
    if (entry) {
        char tag;
        entry->signal.notify(tag, 0);
    }

    if (owner()->first()) {
        Owner* p = owner();
        p->first()->set(savedFirst);
    }

    if (owner()->second()) {
        Owner* p = owner();
        p->second()->set(savedSecond);
    }
}
