// from server: 100% by colin
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long *);

struct Control
{
    virtual ~Control();
    volatile long references;
    void dispose();
};

struct Shared
{
    Control *control;
    ~Shared();
};

struct S
{
    Shared a;
    Shared b;
    Shared c;
    Shared d;
    ~S();
};

__forceinline Shared::~Shared()
{
    if (control)
    {
        if (InterlockedDecrement(&control->references) == 0)
        {
            control->dispose();
            delete control;
        }
        control = 0;
    }
}

S::~S()
{
}
