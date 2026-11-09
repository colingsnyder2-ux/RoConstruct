// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long strong;
    long weak;
};

struct Shared
{
    char* object;
    Control* control;
};

struct Count
{
    Control* control;
    long useCount() const { return control ? control->strong : 0; }
};

struct Entry
{
    char* object;
    Count count;
    Shared* lock(Shared* result);
};

struct Listener
{
    void invoke(char** value);
};

struct S
{
    char padding[16];
    Entry* begin;
    Entry* volatile end;

    void f(Listener* listener);
};

void S::f(Listener* listener)
{
    unsigned int i = 0;
    if (i < (unsigned int)(end - begin))
    {
        do
        {
            if (i >= (unsigned int)(end - begin))
                invalid_parameter_noinfo();

            if (begin[i].count.useCount() != 0)
            {
                if (i >= (unsigned int)(end - begin))
                    invalid_parameter_noinfo();

                Shared temporary;
                char* object = begin[i].lock(&temporary)->object;

                if (temporary.control)
                {
                    Control* owner = temporary.control;
                    if (_InterlockedDecrement(&owner->strong) == 0)
                    {
                        owner->dispose();
                        if (_InterlockedDecrement(&owner->weak) == 0)
                            owner->destroy();
                    }
                }

                char* value = object + 0x228;
                listener->invoke(&value);
            }
            ++i;
        }
        while (i < (unsigned int)(end - begin));
    }
}
