// from server: 70% by atomic.potato
typedef unsigned long DWORD;

extern "C" void __cdecl function_73ab10(DWORD);
typedef void (__thiscall *Function5395b0)(void *);

extern "C" Function5395b0 function_5395b0;

struct S
{
    void f(DWORD *p);
};

void S::f(DWORD *p)
{
    DWORD *q = p + 0x3c;
    if (*q)
        function_73ab10(*q);
    function_5395b0(q);
}
