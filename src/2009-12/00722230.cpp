// from server: 100% by atomic.potato
struct S_func_00722230
{
    unsigned char pad[1];
    unsigned char value;

    void reset();
};

void S_func_00722230::reset()
{
    if (value != 0)
        value = 0;
}
