// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;

    void release();
};

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct String
{
    unsigned char storage[28];

    String(const char*);
    ~String();
};

extern String* (__thiscall *constructString)(String*, const char*);
extern void (__thiscall *destroyString)(String*);

__forceinline String::String(const char* text)
{
    constructString(this, text);
}

__forceinline String::~String()
{
    destroyString(this);
}

struct Stats;

struct Item
{
    virtual void unused();
    virtual void setName(const String&);

    void attach(Stats*);
};

struct Temporary
{
    Item* object;
    Control* control;

    ~Temporary();
};

__forceinline Temporary::~Temporary()
{
    if (control)
        control->release();
}

struct Shared
{
    Item* object;
    Control* control;

    Shared(const Temporary&);
    ~Shared();
};

__forceinline Shared::Shared(const Temporary& source)
    : object(source.object), control(source.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

__forceinline Shared::~Shared()
{
    if (control)
        control->release();
}

Temporary __cdecl createItem(void*);

struct Stats
{
    Item* create(const char*, void*);
};

Item* Stats::create(const char* name, void* argument)
{
    Shared item(createItem(argument));
    {
        String text(name);
        item.object->setName(text);
    }
    item.object->attach(this);
    return item.object;
}
