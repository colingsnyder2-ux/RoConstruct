// from server: 100% by king_originala
struct Descriptor;
struct Context;

struct ThreadStorage {
    void* get();
    void set(void* value);
    void dispose(void* value);
};

ThreadStorage* __cdecl currentStorage();

struct Scope {
    void* saved;

    Scope(int value);
    ~Scope();
};

inline Scope::~Scope()
{
    ThreadStorage* storage = currentStorage();
    void* previous = storage->get();
    if (previous != saved) {
        storage->set(saved);
        if (previous)
            storage->dispose(previous);
    }
}

struct Receiver {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void invoke(Context* context, const Descriptor* descriptor);
};

struct Holder {
    void* object;
    unsigned int reserved;
    Receiver* receiver;

    void operator()(const Descriptor* descriptor);
};

void Holder::operator()(const Descriptor* descriptor)
{
    Scope scope(2);
    Context* context = object
        ? reinterpret_cast<Context*>(static_cast<char*>(object) + 20)
        : 0;
    receiver->invoke(context, descriptor);
}
