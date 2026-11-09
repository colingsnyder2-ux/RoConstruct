// from server: 70% by atomic.potato
typedef unsigned long DWORD;

struct S;

extern "C" DWORD Call0066e2c0(DWORD, DWORD);

struct S {
    DWORD **vtable;
    DWORD pad[6];
    void *object;
    DWORD f(DWORD value);
};

DWORD S::f(DWORD value)
{
    void *p = object;
    DWORD (*method)(void *, DWORD, DWORD) =
        (DWORD (*)(void *, DWORD, DWORD))(*(DWORD ***)p)[2];
    DWORD result = method(p, (DWORD)&value, value);
    return Call0066e2c0(result, (DWORD)&value);
}
