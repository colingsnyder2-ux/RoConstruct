// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Control
{
    long reserved;
    volatile long references;
};

extern char table1[];
extern char table2[];
extern void* sharedObject;
extern Control* sharedControl;

struct S
{
    char reserved[8];
    long field08;
    long field0C;
    long field10;
    void* table;
    void* object;
    Control* control;
    long field20;
    long field24;
    long field28;
    long field2C;
    long field30;
    long field34;
    long field38;

    S();
};

S::S()
{
    field08 = 0;
    field0C = 0;
    field10 = 0;
    table = table1;
    object = sharedObject;
    control = sharedControl;
    if (control)
        _InterlockedIncrement(&control->references);
    field20 = 0;
    field24 = 0;
    field28 = 0;
    field2C = 0;
    field30 = 0;
    table = table2;
    field34 = 0;
    field38 = 0;
}
