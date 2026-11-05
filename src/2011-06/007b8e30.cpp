// from server: 50% by atomic.potato
struct FilterDescendents
{
    int value;
    unsigned char flag;
    float x;
    float y;
    float z;

    FilterDescendents(int value);
};

FilterDescendents::FilterDescendents(int value)
    : value(value), flag(1), x(0.0f), y(0.0f), z(0.0f)
{
}
