// from server: 84% by atomic.potato
struct XItem
{
    float value;
    unsigned short type;

    int __stdcall equals(const XItem& other) const;
};

int __stdcall XItem::equals(const XItem& other) const
{
    if (value == other.value && type == other.type)
        return 1;
    return 0;
}
