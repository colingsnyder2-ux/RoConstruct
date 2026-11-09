// from server: 100% by atomic.potato
struct S
{
    int get() const;
};

int S::get() const
{
    int value = *(const int *)((const char *)this + 0x1ec);
    return value == 1 || value == 2 ? 1 : 0;
}
