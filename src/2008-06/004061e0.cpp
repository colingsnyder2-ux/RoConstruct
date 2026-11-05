// from server: 100% by king_originala
extern "C" void* __stdcall GetState();
int __stdcall ReleaseContext(unsigned long, void*);

struct ThreadState
{
    void* reserved;
    void* current;
};

struct StateGuard
{
    void* previous;
    ThreadState* thread;
    void* context;
    int active;

    StateGuard(void*);
    ~StateGuard();
};

inline StateGuard::~StateGuard()
{
    if (thread)
        thread->current = previous;
    if (active)
        ReleaseContext(0, context);
}

struct Object
{
    bool Query();
};

extern Object globalObject;

bool Function()
{
    StateGuard guard(GetState());
    return globalObject.Query();
}
