// from server: 100% by colin
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void *);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void *);

struct LockGuard
{
    void *section;
    bool locked;

    LockGuard(void *);
    ~LockGuard();
};

inline LockGuard::LockGuard(void *p) : section(p)
{
    EnterCriticalSection(section);
    locked = true;
}

inline LockGuard::~LockGuard()
{
    if (locked)
        LeaveCriticalSection(section);
}

struct DxUserInput
{
    char padding0[0x34];
    char criticalSection[0x18];
    char padding1[0x12C];
    int state;
    char padding2[0x14];
    bool requested;
    char padding3;
    bool current;

    void enable(int);
    void disable();
    void update(int);
};

void DxUserInput::update(int argument)
{
    LockGuard lock(criticalSection);

    if (state == 0)
    {
        current = false;
    }
    else if (current != requested)
    {
        if (requested)
            enable(argument);
        else
            disable();
    }
}
