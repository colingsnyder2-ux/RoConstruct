// from server: 83% by atomic.potato
extern void G1_func_0040C080();

struct S
{
    int value;
    int set(int);
};

int S::set(int value)
{
    if (value != *(int*)((char*)this + 0xcc))
    {
        *(int*)((char*)this + 0xcc) = value;
        G1_func_0040C080();
    }
    return 0;
}
