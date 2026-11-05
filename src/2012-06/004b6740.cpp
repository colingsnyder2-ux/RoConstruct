// from server: 100% by tester
extern "C" long __declspec(dllimport) __stdcall InterlockedDecrement(long *);

struct CEnumMediaTypes
{
    int f(void *);
};

int CEnumMediaTypes::f(void *p)
{
    int *state = (int *)p;
    int result = InterlockedDecrement((long *)((char *)state + 0x10));

    if (!result && state)
    {
        int **vtable = (int **)state;
        ((void (__thiscall *)(void *, int))vtable[0][7])(state, 1);
    }

    return result;
}
