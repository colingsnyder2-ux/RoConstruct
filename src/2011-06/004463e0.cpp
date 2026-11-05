// from server: 82% by atomic.potato
struct XItem
{
    int f(float const* a, float const* b);
};

int XItem::f(float const* a, float const* b)
{
    return (*a == *b) ? 1 : 0;
}
