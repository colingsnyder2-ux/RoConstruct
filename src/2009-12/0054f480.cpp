// from server: 100% by atomic.potato
struct S
{
    bool f(const unsigned short* value);
};

bool S::f(const unsigned short* value)
{
    return *(const unsigned short*)this == *value;
}
