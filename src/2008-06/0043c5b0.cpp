// from server: 100% by king_originala
struct Context {
    unsigned long fields[3];
    Context();
    ~Context();
    void attach(void *);
};

inline Context::Context() {
    fields[0] = 0;
    fields[1] = 0;
}

struct ScopedContext : Context {
    ScopedContext(void *);
};

inline ScopedContext::ScopedContext(void *value) {
    fields[2] = 0;
    attach(value);
}

struct Owner {
    char padding[0x198];
    void *handle;
};

struct Receiver;

struct ReceiverTable {
    void *padding[15];
    void (__thiscall *invoke)(Receiver *, void *, unsigned long);
};

struct Receiver {
    ReceiverTable *table;
};

struct Item {
    char padding[0x130];
    Owner *owner;
    Receiver *receiver;
    void execute(void *, const unsigned long *);
};

void Item::execute(void *object, const unsigned long *value) {
    void *adjusted = 0;
    ScopedContext context(owner->handle);
    if (object)
        adjusted = static_cast<char *>(object) + 0x14;
    receiver->table->invoke(receiver, adjusted, *value);
}
