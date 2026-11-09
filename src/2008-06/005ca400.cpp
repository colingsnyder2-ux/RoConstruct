// from server: 100% by atomic.potato
float g_value;

struct Item
{
    float get() const;
};

float Item::get() const
{
    if (*((unsigned char*)this + 4) != 0)
        return 1.0f;
    if (*((unsigned char*)this + 5) != 0)
        return g_value;
    return 0.0f;
}
