// from server: 61% by atomic.potato
struct S
{
    struct String
    {
        int value[8];
    };

    String value;
    int f(String *arg);
};

extern "C" void __stdcall copy_string(S::String *, const S::String *);

int S::f(String *arg)
{
    copy_string(&value, arg);
    arg->value[7] = value.value[7];
    return (int)arg;
}
