// from server: 70% by atomic.potato
struct S
{
    int Get();
};

extern "C" void Call684200(int, int, int);

int S::Get()
{
    int value = 0;
    do
    {
        value = Get();
        if (value == 0)
            break;
        Call684200(value, 0, 0);
    } while (Get() != 0);
    return 0;
}
