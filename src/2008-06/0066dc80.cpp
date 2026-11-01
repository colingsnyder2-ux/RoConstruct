// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)

struct PartInstance;

struct GetSetImpl
{
    static PartInstance* get(PartInstance*);
};

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;

    volatile long strong;
    volatile long weak;

    void releaseWeak()
    {
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }

    void releaseStrong()
    {
        if (_InterlockedDecrement(&strong) == 0)
        {
            dispose();
            releaseWeak();
        }
    }
};

struct Shared
{
    PartInstance* pointer;
    Control* control;

    ~Shared()
    {
        if (control)
            control->releaseStrong();
    }
};

Shared __cdecl acquire(PartInstance*);

struct Weak
{
    PartInstance* pointer;
    Control* control;

    Weak() : pointer(0), control(0) {}

    ~Weak()
    {
        if (control)
            control->releaseWeak();
    }

    void assign(const Shared& value)
    {
        pointer = value.pointer;
        Control* replacement = value.control;
        if (replacement)
            _InterlockedIncrement(&replacement->weak);
        if (control)
            control->releaseWeak();
        control = replacement;
    }

    void swap(Weak& other)
    {
        if (&pointer != &other.pointer)
        {
            PartInstance* saved = pointer;
            pointer = other.pointer;
            other.pointer = saved;
        }
        Control* saved = control;
        control = other.control;
        other.control = saved;
    }
};

struct GroupDragTool
{
    char padding0[8];
    Weak selected;
    char padding1[20];
    PartInstance* part;

    void update();
};

void GroupDragTool::update()
{
    if (part)
        selected.assign(acquire(GetSetImpl::get(part)));
    else
        Weak().swap(selected);
}
