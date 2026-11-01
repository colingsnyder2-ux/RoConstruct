// from server: 100% by colin
// from server: 85% by king_originala
typedef void (__thiscall *Callback)(void*, int);

struct S {
    Callback volatile callback;
    char* volatile object;
    volatile int adjustment;
    volatile int argument;
};

void __cdecl f(S* p)
{
    int argument = p->argument;
    int adjustment = p->adjustment;
    p->callback(p->object + adjustment, argument);
}
