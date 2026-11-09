// from server: 67% by atomic.potato
extern "C" void __cdecl sub_51D740(int);
extern "C" void __cdecl sub_982114(int);

struct S
{
    int f();
    int unused;
    int value;
    char reserved[1];
    char flag;
};

int S::f()
{
    if (value != 0)
    {
        if (flag != 0)
            sub_51D740(value);

        sub_982114(value);
    }

    return value;
}
