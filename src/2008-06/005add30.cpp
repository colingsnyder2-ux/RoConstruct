// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;
};

struct Output
{
    void __cdecl print(int, const char *, ...);
};

struct Handle
{
    Output *object;
    Control *control;

    Output *operator->() const;
    ~Handle();
};

inline Output *Handle::operator->() const
{
    return object;
}

inline Handle::~Handle()
{
    if (control)
    {
        Control *p = control;
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

int __cdecl sub_611eb0(void *, int);
const char *__cdecl sub_612010(void *, int, unsigned int *);
Handle __cdecl sub_569620();
int *__cdecl sub_493760();

int __cdecl sub_5add30(void *state)
{
    if (sub_611eb0(state, -1))
    {
        sub_569620()->print(0, "%s %d",
                           sub_612010(state, -1, 0),
                           *sub_493760());
    }
    else
    {
        sub_569620()->print(0, "Current identity is %d",
                           *sub_493760());
    }
    return 0;
}
