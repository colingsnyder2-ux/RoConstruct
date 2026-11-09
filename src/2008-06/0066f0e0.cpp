// from server: 60% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct State;
struct Actor;
struct Part;
struct Service;

struct Counts {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Reference {
    Counts *value;
    Reference &assign(const Reference &);
    ~Reference();
};

inline Reference::~Reference()
{
    Counts *p = value;
    if (p && _InterlockedExchangeAdd(&p->strong, -1) == 0) {
        p->dispose();
        if (_InterlockedExchangeAdd(&p->weak, -1) == 0)
            p->destroy();
    }
}

struct SharedActor {
    Part *object;
    Reference reference;
};

struct Rotation {
    float elements[9];
};

struct Transform {
    Rotation rotation;
    float x, y, z;
    Transform();
};

struct Switch {
    void set(int);
};

struct Result {
    void finish();
};

struct Link {
    Result *get(void *);
};

struct Actor {
    char padding[0x21c];
    Link *link;
    void *source();
};

struct Part {
    char padding[0x228];
    Switch flag;
    const Transform *transform();
};

struct Service {
    void attach(Part *);
};

struct ConnectionResult {
    char storage[20];
    ~ConnectionResult();
};

struct Connection {
    long first, second, third;
    Connection();
    Connection &assign(const ConnectionResult &);
    ~Connection();
};

inline Connection::Connection() : first(0), second(0), third(0) {}

extern void __cdecl callback();

struct Binding {
    void (__cdecl *function)();
    int adjustment;
    State *object;
};

struct Function {
    char storage[40];
    Function(const Binding &);
    ~Function();
};

struct Dispatcher {
    ConnectionResult connect(void *, const Function &, int);
};

struct Animation {
    char padding[0x10];
    struct Channel {
        void set(Actor **, float);
    } channel;
};

struct Registry {
    Animation *find(void *);
};

extern Dispatcher dispatcher;
extern Registry registry;
extern SharedActor __cdecl acquire(void *);
extern Service *__cdecl findService(Actor *);

struct Prefix {
    char storage[0xa0];
    ~Prefix();
};

struct Token {
    char storage[0x24];
    ~Token();
};

struct State {
    Prefix prefix;
    Token token;
    Part *part;
    Reference reference;
    Service *service;
    Connection connection;
    unsigned char firstFlag;
    char gap[3];
    unsigned char secondFlag;
    char gap2[3];
    Transform frame;

    void assignActor(const SharedActor &);
    State(Actor *);
};

inline void State::assignActor(const SharedActor &value)
{
    part = value.object;
    reference.assign(value.reference);
}

State::State(Actor *actor)
    : part(0), service(0), firstFlag(0), secondFlag(0)
{
    Transform &destination = frame;
    assignActor(acquire(actor->source()));

    if (part) {
        const Transform *source = part->transform();
        destination.rotation = source->rotation;
        destination.x = source->x;
        destination.y = source->y;
        destination.z = source->z;

        part->flag.set(1);

        Binding binding;
        binding.function = callback;
        binding.adjustment = 0;
        binding.object = this;
        {
            Function function(binding);
            connection.assign(dispatcher.connect(
                part ? reinterpret_cast<char *>(part) + 0x14 : 0,
                function, 10));
        }

        Actor *owner = actor;
        service = findService(owner);
        service->attach(part);
        owner->link->get(&token)->finish();
    }

    Animation *animation = registry.find(
        actor ? reinterpret_cast<char *>(actor) + 0x14 : 0);
    if (animation)
        animation->channel.set(&actor, 0.0f);
}
