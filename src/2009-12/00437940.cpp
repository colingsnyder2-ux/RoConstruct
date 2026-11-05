// from server: 47% by atomic.potato
struct S
{
    float value;
    unsigned short type;
    bool f(const S& other);
};

bool S::f(const S& other)
{
    if (value == other.value)
        return false;
    if (type != other.type)
        return false;
    return true;
}
