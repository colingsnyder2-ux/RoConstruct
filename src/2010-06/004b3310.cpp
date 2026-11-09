// from server: 81% by atomic.potato
typedef void (__thiscall *Callback)(double);

struct S
{
};

void __cdecl f(void *p, double value)
{
    Callback fn = *(Callback *)((char *)p + 0);
    fn(value);
}
