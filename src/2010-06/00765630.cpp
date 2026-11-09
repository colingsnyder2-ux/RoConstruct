// from server: 100% by atomic.potato
struct FilterStairs
{
    int IsValid();
};

int FilterStairs::IsValid()
{
    if (*(int *)this == 10)
    {
        int value = *((int *)this + 2);
        if (value == 8 || value == 127)
            return 1;
    }
    return 0;
}
