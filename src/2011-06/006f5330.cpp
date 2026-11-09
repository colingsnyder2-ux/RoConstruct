// from server: 54% by atomic.potato
struct S
{
    char padding[180];
    int value;
    void set(int);
};

void S::set(int v)
{
    if (value != v)
    {
        value = v;
        value = 0x00CD2288;
    }
}
