// from server: 55% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sprintf(char*, const char*, ...);

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct RBX_DataModel
{
    char pad[0x20c];
    void* field_214;
    double get() const;
};

struct Pair
{
    RBX_DataModel* pointer;
    Control* control;
};

struct Guard
{
    char storage[12];
    Guard(Pair);
    ~Guard();
};

struct Output
{
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void set(const char*);
};

struct Source;

struct S
{
    unsigned char padding[0x94];
    Source* source;
    Pair* f(Pair*);
    void func_00450c80(Output*);
};

void S::func_00450c80(Output* output)
{
    Pair initial;
    Pair value = *f(&initial);

    if (value.control)
        _InterlockedExchangeAdd(&value.control->strong, 1);

    Guard guard(value);

    Control* control = initial.control;
    if (control && _InterlockedExchangeAdd(&control->strong, -1) == 0)
    {
        control->dispose();
        if (_InterlockedExchangeAdd(&control->weak, -1) == 0)
            control->destroy();
    }

    Pair model;
    char buffer[32];
    sprintf(buffer, "%.3gfps", f(&model)->pointer->get());

    control = model.control;
    if (control && _InterlockedExchangeAdd(&control->strong, -1) == 0)
    {
        control->dispose();
        if (_InterlockedExchangeAdd(&control->weak, -1) == 0)
            control->destroy();
    }

    output->set(buffer);
}
