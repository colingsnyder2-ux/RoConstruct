// from server: 66% by atomic.potato
struct Flag
{
    int value_1bc;
    int get(int *arg);
};

int Flag::get(int *arg)
{
    unsigned char enabled = *((unsigned char *)arg + 0xb0);
    if (!enabled)
        return 0;
    return *((int *)((char *)arg + 0xac)) != value_1bc;
}
