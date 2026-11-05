// from server: 80% by atomic.potato
struct S
{
    char pad[0x1b8];
    int value;
    void setValue(int);
};

extern "C" void __stdcall target(int, int);

void S::setValue(int v)
{
    if (v < 0)
        v = 1;
    if (v == value)
        return;
    value = v;
    target(v, 0xe21df4);
}
