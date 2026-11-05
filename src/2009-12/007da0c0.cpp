// from server: 95% by atomic.potato
typedef void (__cdecl *Function)(void *);

extern "C" void __cdecl Function_007da140(void *);
extern "C" void __cdecl Function_006ed740(void *);

struct S
{
    void f(void *);
};

void S::f(void *value)
{
    Function_007da140(value);
    Function_006ed740(value);
}
