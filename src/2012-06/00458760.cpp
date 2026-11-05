// from server: 82% by atomic.potato
struct XItem
{
    static int __stdcall Compare(const float* a, const float* b);
};

int __stdcall XItem::Compare(const float* a, const float* b)
{
    return *a == *b;
}
