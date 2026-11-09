// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


extern double clockTime();
extern unsigned char timingEnabled;
extern const double timeScale;

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* pointer;
    Control* control;

    __forceinline Shared(const Shared& other);
    __forceinline ~Shared();
};

__forceinline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control) {
    if (control) {
        volatile long* count = &control->strong;
        _InterlockedIncrement(count);
    }
}

__forceinline Shared::~Shared() {
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Stopwatch {
    char storage[0x60];
    void stop();
    void start();
};

struct S {
    char padding[0x1c0];
    float interval;
    char padding2[0x14];
    double previous;
    double current;
    Stopwatch stopwatch;
    unsigned char stopped;

    void run(Shared owner);
    void update(Shared owner);
    void advance();
    void adjust(double value);
    void wait(double value);
};

void S::run(Shared owner) {
    double remaining = 0.0;
    double deadline = clockTime();

    for (;;) {
        if (timingEnabled) {
            double candidate = clockTime() - interval;
            const double& selected = candidate > deadline ? candidate : deadline;
            deadline = interval + selected;
        } else {
            deadline = clockTime();
        }

        if (stopped)
            return;

        update(owner);
        if (stopped)
            break;

        advance();
        if (stopped)
            break;

        remaining = (deadline - clockTime() + remaining) * timeScale;
        adjust(remaining);

        if (remaining > 0.0)
            wait(remaining);

        if (stopped)
            break;

        stopwatch.stop();
        stopwatch.start();
        previous = current;
        current = 0.0;
    }
}
