// from server: 48% by atomic.potato
extern "C" void __cdecl Function762e30(int);
extern "C" void __cdecl Function762b50();

struct S {
    char padding[16];
    int value;
    void f();
};

void S::f()
{
    int state = value;
    if (state == 0)
        Function762e30(1);
    else
    {
        state = state - 1;
        if (state == 0)
            Function762e30(3);
        else
        {
            state = state - 1;
            if (state == 0)
                Function762e30(1);
            else
                Function762b50();
        }
    }
}
