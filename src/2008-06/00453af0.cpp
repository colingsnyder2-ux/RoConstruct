// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedIncrement)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    long use_count;
    long weak_count;
    void add_ref();
    void release();
};

inline void Control::add_ref()
{
    _InterlockedIncrement(&use_count);
}

inline void Control::release()
{
    if (_InterlockedDecrement(&use_count) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak_count) == 0)
            destroy();
    }
}

struct World;

struct Object {
    World* getWorld();
};

struct Shared {
    Object* object;
    Control* control;
    ~Shared();
    World* getWorld() const;
};

inline Shared::~Shared()
{
    if (control)
        control->release();
}

inline World* Shared::getWorld() const
{
    return object ? object->getWorld() : 0;
}

struct GuardShared {
    Object* object;
    Control* control;
    GuardShared(const Shared& other);
    ~GuardShared();
};

inline GuardShared::GuardShared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        control->add_ref();
}

inline GuardShared::~GuardShared()
{
    if (control)
        control->release();
}

struct Holder {
    Shared get();
};

struct Guard {
    char storage[12];
    Guard(GuardShared value);
    ~Guard();
};

struct Entry {
    void* first;
    void* second;
};

struct Entries {
    char padding[12];
    Entry* begin;
    Entry* end;
};

struct World {
    char padding[0x154];
    Entries* entries;
};

struct Command {
    virtual void enable(int value);
};

struct CRobloxDoc {
    char padding[0x94];
    Holder* holder;
    void update(Command* command);
};

void CRobloxDoc::update(Command* command)
{
    Guard guard(holder->get());
    World* world = holder->get().getWorld();
    command->enable((unsigned int)(world->entries->end -
                                  world->entries->begin) > 0);
}
