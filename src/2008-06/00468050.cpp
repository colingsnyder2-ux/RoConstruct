// from server: 100% by colin
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct Guard {
    void* section;
    bool locked;

    explicit Guard(void* p) : section(p)
    {
        EnterCriticalSection(section);
        locked = true;
    }

    ~Guard()
    {
        if (locked)
            LeaveCriticalSection(section);
    }
};

struct S {
    unsigned char reserved0[0x34];
    unsigned char criticalSection[0x18];
    unsigned char reserved1[0x145];
    bool enabled;

    void update();
    void f(bool value);
};

void S::f(bool value)
{
    Guard guard(criticalSection);
    enabled = value;
    update();
}
