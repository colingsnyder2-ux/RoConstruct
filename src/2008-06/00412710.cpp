// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct CChatPrompt;

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;

    void release();
};

struct Handle
{
    Control* p;
    Handle& operator=(const Handle&);
};

struct Object
{
    void attach(CChatPrompt*);
};

struct Shared
{
    Object* px;
    Handle pn;
    ~Shared();
};

extern Shared __cdecl create_shared();
extern unsigned __cdecl current_index();
extern void __cdecl register_callback(void (__cdecl*)(), void*);
extern void __cdecl callback();
extern char callback_data;
extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct CChatPrompt
{
    char padding[0x19c];
    Shared* first;
    Shared* last;

    Object* existing();
    Object* func_00412710();
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

__forceinline Shared::~Shared()
{
    if (pn.p)
        pn.p->release();
}

Object* CChatPrompt::func_00412710()
{
    Object* result = existing();
    if (!result)
    {
        Shared value = create_shared();
        result = value.px;
        register_callback(callback, &callback_data);

        unsigned index = current_index();
        if (index >= static_cast<unsigned>(last - first))
            _invalid_parameter_noinfo();

        Shared& slot = first[index];
        slot.px = value.px;
        slot.pn = value.pn;
        result->attach(this);
    }
    return result;
}
