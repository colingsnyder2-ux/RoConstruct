// from server: 100% by king_originala
extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)
#pragma float_control(precise, off, push)

struct Signal {
    void fire(const float*, float);
};

struct Entry {
    char padding[0x10];
    Signal signal;
};

struct Registry {
    Entry* find(void*);
};

extern Registry registry;

struct Climbing {
    char padding[0xb8];
    float x;
    float y;
    float z;

    void update(float, int);
    void baseUpdate(float, int);
    bool isActive();
    void* owner();
};

void Climbing::update(float dt, int step)
{
    baseUpdate(dt, step);
    if (isActive()) {
        void* p = owner();
        void* key = p ? static_cast<char*>(p) + 0x14 : 0;
        float speed = static_cast<float>(sqrt(x * x + y * y + z * z));
        Entry* entry = registry.find(key);
        if (entry)
            entry->signal.fire(&speed, speed);
    }
}

#pragma float_control(pop)
