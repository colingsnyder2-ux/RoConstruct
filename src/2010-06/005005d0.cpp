// from server: 80% by atomic.potato
extern "C" int __cdecl InterlockedIncrement(long *);

struct S
{
    S();
    int value0;
    int value4;
    char value8;
    int valueC;
    int value10;
};

extern "C" void __cdecl sub_500540(S *);
extern long global_9EA380;
extern const char global_C06994[];

S::S()
{
    sub_500540(this);
    global_9EA380 = 0;
    *(int *)this = 0xA1C8A8;
    value8 = 0;
    valueC = InterlockedIncrement(&global_9EA380);
    value10 = 0;
}
