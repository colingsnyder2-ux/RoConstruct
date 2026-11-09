// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* object;
    Control* control;

    Shared(const Shared& other)
        : object(other.object), control(other.control)
    {
        if (control)
            _InterlockedIncrement(&control->strong);
    }

    ~Shared()
    {
        Control* p = control;
        if (p && _InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
};

struct Holder
{
    Shared value;
    Holder(Shared);
    ~Holder();
};

struct Base
{
    virtual void method();
    char storage[120];
    Base();
};

struct CRobloxReportDocView : Holder, Base
{
    int value;
    CRobloxReportDocView(int, Shared);
};

CRobloxReportDocView::CRobloxReportDocView(int n, Shared p)
    : Holder(p), Base(), value(n)
{
}
