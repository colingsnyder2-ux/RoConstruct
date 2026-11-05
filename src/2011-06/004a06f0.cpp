// from server: 100% by atomic.potato
extern "C" int __declspec(dllimport) __stdcall InterlockedDecrement(long *);

struct CEnumPins
{
    long value;
    int f(void *);
};

int CEnumPins::f(void *arg)
{
    int result = InterlockedDecrement((long *)((char *)arg + 0x14));
    int saved = result;
    if (result == 0 && arg != 0)
        result = ((int (__thiscall *)(CEnumPins *, int))(*(unsigned long **)((char *)arg))[0x1c / 4])((CEnumPins *)arg, 1);
    return saved;
}
