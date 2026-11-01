// from server: 100% by king_originala
struct Base {
    virtual ~Base();
    char* get();
};

struct Secondary {
    virtual void action() = 0;
};

struct Container {
    void erase(char*, int);
};

struct Entry {
    char padding[16];
    Container container;
};

struct Registry {
    Entry* find(void*);
};

extern Registry registry;

struct FallingDown : Base, Secondary {
    virtual ~FallingDown();
    virtual void action();
};

FallingDown::~FallingDown()
{
    char token;
    char* object = get();
    Entry* entry = registry.find(object ? object + 20 : 0);
    if (entry)
        entry->container.erase(&token, 0);
}
