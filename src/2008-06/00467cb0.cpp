// from server: 100% by colin
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void *);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void *);
extern int __cdecl translateKey(int);

struct Lock {
    void *section;
    bool locked;
    Lock(void *);
    ~Lock();
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

struct S {
    char pad0[0x34];
    char section[24];
    char pad1[0x1c];
    unsigned char keys[256];
    int specialKey;
    bool f(int);
};

bool S::f(int key)
{
    Lock lock(section);
    if (specialKey && key == specialKey)
        return true;
    if (keys[translateKey(key)] & 0x80)
        return true;
    return false;
}
