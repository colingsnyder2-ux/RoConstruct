// from server: 50% by atomic.potato
struct S
{
    int value;
    char padding[16];
    int *object;
    ~S();
};

extern "C" void __cdecl std_exception_destructor(S *);
extern "C" void __cdecl target(S *);

S::~S()
{
    value = 0x00b98fcc;
    object = (int *)0x00b98fc4;
    object = (int *)0x00b43e60;
    if (object != 0)
        ((void (__fastcall *)(int *))(*(int **)object + 0x10))(object);
    target(this);
}
