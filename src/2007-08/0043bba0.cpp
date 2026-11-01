// from server: 100% by colin
struct MVCXTPPropertyGridItemXItem
{
    bool equal(const float* a, const float* b) const;
};

bool MVCXTPPropertyGridItemXItem::equal(const float* a, const float* b) const
{
    return *a == *b;
}
