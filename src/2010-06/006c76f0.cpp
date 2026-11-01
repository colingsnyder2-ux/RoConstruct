// from server: 100% by atomic.potato
extern "C" void __cdecl sub_7a799a(int);

struct S
{
    char pad[12];
    int value;
    void release();
};

void S::release()
{
    if (value)
    {
        sub_7a799a(value);
    }
}
