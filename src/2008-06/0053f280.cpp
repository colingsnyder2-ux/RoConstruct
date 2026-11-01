// from server: 100% by king_originala
struct Key
{
    bool less(const Key& other) const;
    bool greater(const Key& other) const;
};

struct S
{
    unsigned char first;
    unsigned char second;
    float value;
    Key key;

    bool operator<(const S& other) const;
};

#pragma optimize("", off)

bool S::operator<(const S& other) const
{
    if (key.less(other.key))
        return true;

    if (key.greater(other.key))
        return false;

    if (first < other.first)
        return true;

    if (first > other.first)
        return false;

    if (value < other.value)
        return true;

    if (value > other.value)
        return false;

    if (second < other.second)
        return true;

    return false;
}
