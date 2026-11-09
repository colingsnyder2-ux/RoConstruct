// from server: 100% by king_originala
extern "C" {
    extern void (__stdcall *EnterCriticalSection)(void*);
    extern void (__stdcall *LeaveCriticalSection)(void*);
}

struct Lock {
    void* section;
    bool held;

    inline Lock(void*);
    inline ~Lock();
};

inline Lock::Lock(void* p) : section(p), held(false)
{
    EnterCriticalSection(section);
    held = true;
}

inline Lock::~Lock()
{
    if (held)
        LeaveCriticalSection(section);
}

struct Device;

struct DeviceTable {
    void* unused[9];
    long (__stdcall *getState)(Device*, unsigned long, void*);
};

struct Device {
    DeviceTable* table;
};

struct Owner {
    void update();
    void updateFirst();
    void updateSecond();
};

struct S {
    char padding0[8];
    char section[24];
    char padding1[28];
    unsigned char state[256];
    char padding2[20];
    Device* device;
    char padding3[18];
    bool firstEnabled;
    bool secondEnabled;

    void f(int, int, int);
};

void S::f(int, int, int)
{
    Lock lock(section);
    Owner* owner = reinterpret_cast<Owner*>(
        reinterpret_cast<char*>(this) - 0x2c);

    owner->update();

    if (firstEnabled)
        owner->updateFirst();

    Device* current = device;
    if (current)
        current->table->getState(current, 0x100, state);

    if (secondEnabled)
        owner->updateSecond();

    LeaveCriticalSection(lock.section);
    lock.held = false;
}
