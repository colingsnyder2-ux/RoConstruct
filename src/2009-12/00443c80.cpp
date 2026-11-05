// from server: 45% by atomic.potato
typedef unsigned int DWORD;

struct S
{
    DWORD value;
};

struct T
{
    DWORD field_1c;
    DWORD f(DWORD, DWORD);
};

extern "C" DWORD __stdcall sub_443980(S *, DWORD);

DWORD T::f(DWORD a, DWORD b)
{
    S value;
    DWORD result = sub_443980(&value, b);
    S *object = (S *)field_1c;
    DWORD (*method)(S *, S *, DWORD) =
        (DWORD (*)(S *, S *, DWORD))(*(DWORD *)*(DWORD **)object + 0x10);
    return method(object, &value, result);
}
