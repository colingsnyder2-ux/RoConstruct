// from server: 100% by atomic.potato
extern "C" long __declspec(dllimport) __stdcall InterlockedDecrement(long *);

struct CEnumPins
{
    int Next(CEnumPins *p);
};

int CEnumPins::Next(CEnumPins *p)
{
    int result = InterlockedDecrement((long *)((char *)p + 0x14));
    if (result == 0 && p != 0)
        ((void (__thiscall *)(CEnumPins *, int))(*(int **)(p))[7])(p, 1);
    return result;
}
