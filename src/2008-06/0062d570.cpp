// from server: 100% by king_originala
struct Owner;

struct Pair {
    void* object;
    void* control;
    Pair();
    Pair(const Pair&);
    ~Pair();
};

inline Pair::~Pair()
{
}

extern "C" void* __cdecl runtimeCast(
    void*, int, const void*, const void*, int);

Pair __cdecl makePair(Owner*);
void __cdecl update(Pair, int, int);

struct Callback {
    void (__cdecl* function)(Pair, int, int);
    int argument;
    int frame;
};

struct Owner {
    void apply(Callback);
};

struct ForceField {
    char padding[16];
    unsigned char initialized;
    char alignment[3];
    int frame;

    void step(int argument);
};

void ForceField::step(int argument)
{
    Owner* owner = reinterpret_cast<Owner**>(this)[-11];

    if (initialized &&
        !runtimeCast(owner, 0,
                     reinterpret_cast<const void*>(0x92907C),
                     reinterpret_cast<const void*>(0x9481B8), 0))
    {
        frame = (frame + 1) % 30;

        Callback callback;
        callback.function = update;
        callback.argument = argument;
        callback.frame = frame;
        owner->apply(callback);

        update(makePair(owner), argument, frame);
    }

    initialized = 1;
}
