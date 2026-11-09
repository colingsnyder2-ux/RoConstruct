// from server: 100% by king_originala
typedef unsigned long DWORD;

extern "C" {
    extern void (__stdcall *const EnterCriticalSection)(void *);
    extern void (__stdcall *const LeaveCriticalSection)(void *);
    extern unsigned int (__stdcall *const MapVirtualKeyA)(unsigned int, unsigned int);
    extern unsigned int (__stdcall *const SendInput)(unsigned int, void *, int);
}

struct Lock {
    void *section;
    bool locked;
    Lock(void *);
    ~Lock();
    void unlock();
};

inline Lock::Lock(void *p) : section(p)
{
    EnterCriticalSection(section);
    locked = true;
}

inline Lock::~Lock()
{
    if (locked)
        LeaveCriticalSection(section);
}

inline void Lock::unlock()
{
    LeaveCriticalSection(section);
    locked = false;
}

struct State {
    char padding0[0x34];
    char section[0x18];
    char padding1[0x147];
    bool enabled;
    void setEnabled(bool);
};

struct Input {
    DWORD type;
    DWORD key;
    DWORD scan;
    DWORD flags;
    DWORD time;
    DWORD extra;
    DWORD padding;
};

struct S {
    char padding[0x84];
    State *state;
    void f();
    void cleanup();
    void finish();
    void sendKeys();
};

void S::f()
{
    cleanup();
    finish();
}

void S::sendKeys()
{
    Lock lock(state->section);
    bool enabled = state->enabled;
    if (enabled)
        state->setEnabled(false);

    Input inputs[4];

    inputs[0].type = 1;
    inputs[0].key = 0x12;
    inputs[0].scan = MapVirtualKeyA(0x12, 0);
    inputs[0].flags = 0;
    inputs[0].time = 0;
    inputs[0].extra = 0;
    inputs[0].padding = 0;

    inputs[1].type = 1;
    inputs[1].key = 0x2c;
    inputs[1].scan = MapVirtualKeyA(0x2a, 0);
    inputs[1].flags = 0;
    inputs[1].time = 0;
    inputs[1].extra = 0;
    inputs[1].padding = 0;

    inputs[2].type = 1;
    inputs[2].key = 0x2c;
    inputs[2].scan = MapVirtualKeyA(0x2a, 0);
    inputs[2].flags = 2;
    inputs[2].time = 0;
    inputs[2].extra = 0;
    inputs[2].padding = 0;

    inputs[3].type = 1;
    inputs[3].key = 0x12;
    inputs[3].scan = MapVirtualKeyA(0x12, 0);
    inputs[3].flags = 2;
    inputs[3].time = 0;
    inputs[3].extra = 0;
    inputs[3].padding = 0;

    SendInput(4, inputs, 28);

    if (enabled)
        state->setEnabled(true);

    lock.unlock();
}
