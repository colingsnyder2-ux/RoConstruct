// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct Triple {
    unsigned int a, b, c;
};

struct Base {
    unsigned int reserved;

    Base();
    ~Base();
};

inline Base::Base() : reserved(0) {}

struct EventHandler {
    void* state;
    unsigned int reserved;
    Triple payload;

    EventHandler(Triple value, unsigned int unused);
    ~EventHandler();
};

struct Object {
    char storage[40];

    Object();
};

struct Holder {
    void* state;
    Base base;
    EventHandler handler;

    Holder(const Triple& value);
    void set(Object* object);
    void finish();
};

Holder::Holder(const Triple& value)
    : state(0), base(), handler(value, 0) {
    set(new Object);
    finish();
}
