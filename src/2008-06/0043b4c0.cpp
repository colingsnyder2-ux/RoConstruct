// from server: 100% by atomic.potato
struct XItem
{
    static int __stdcall Equal(const void* a, const void* b);
};

int __stdcall XItem::Equal(const void* a, const void* b)
{
    return *(const int*)a == *(const int*)b;
}
