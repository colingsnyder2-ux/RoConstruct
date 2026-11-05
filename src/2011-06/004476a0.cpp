// from server: 71% by atomic.potato
struct S
{
    int f(const S& value) const;
    float x;
    unsigned short y;
};

int S::f(const S& value) const
{
    if (x == value.x && y == value.y)
        return 1;
    return 0;
}
