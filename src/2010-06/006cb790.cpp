// from server: 50% by atomic.potato
typedef void *(__thiscall *Callback)(void *, void *);

extern "C" void __stdcall Function0060fb10(void *, int);

struct S
{
    void *field00;
    void *field1c;
    void f(void *);
};

void S::f(void *arg)
{
    void *value;
    Callback callback;

    callback = *(Callback *)(*(char **)((char *)field1c) + 12);
    value = 0;
    value = callback(field1c, arg);
    Function0060fb10(value, 0);
}
