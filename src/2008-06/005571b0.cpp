// from server: 100% by colin
// from server: 97% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct StepEvent {
    float time;
    float delta;

    StepEvent(float t, float d) : time(t), delta(d) {}
};

struct StepSignal {
    unsigned char storage[0x68];
    void fire(StepEvent event);
};

struct UpdateSignal {
    void fire(const float& delta, float time, float step);
};

struct Receiver {
    unsigned char padding[0x10];
    UpdateSignal signal;
};

struct Registry {
    Receiver* find(void* key);
};

extern Registry registry;

struct Pad { unsigned char padding0[0x14]; };
struct Key { unsigned char data[0x13C]; };
struct S : Pad, Key {
    StepSignal signal;
    double elapsed;

    void step(float delta);
};

void S::step(float delta)
{
    float time = (float)(elapsed += delta);
    signal.fire(StepEvent(time, delta));

    Receiver* receiver = registry.find(static_cast<Key*>(this));
    if (receiver)
        receiver->signal.fire(delta, time, delta);
}
