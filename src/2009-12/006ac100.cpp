// from server: 100% by atomic.potato
struct S
{
    int pad[49];
    int value;
    void set(int);
};

extern "C" void __stdcall dispatch(int);

void S::set(int v)
{
    if (v != value)
    {
        value = v;
        dispatch(0x00B9184C);
    }
}
