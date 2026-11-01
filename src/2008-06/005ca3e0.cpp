// from server: 100% by atomic.potato
struct StatsItem
{
    float get() const;
};

float g_value;

float StatsItem::get() const
{
    if (*((const unsigned char*)this + 2) != 0)
        return 1.0f;
    if (*((const unsigned char*)this + 3) != 0)
        return g_value;
    return 0.0f;
}
