// from server: 100% by atomic.potato
struct FilterStairs
{
    int IsValid();
};

int FilterStairs::IsValid()
{
    if (*(int *)this == 10 && *((int *)this + 2) == 12)
        return 1;
    return 0;
}
