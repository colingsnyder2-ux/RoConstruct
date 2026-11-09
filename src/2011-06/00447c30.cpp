// from server: 100% by atomic.potato
struct HVCXTPPropertyGridItem
{
    static int __stdcall XItem(const HVCXTPPropertyGridItem* a,
                               const HVCXTPPropertyGridItem* b);
};

int __stdcall HVCXTPPropertyGridItem::XItem(
    const HVCXTPPropertyGridItem* a,
    const HVCXTPPropertyGridItem* b)
{
    return *(const int*)a == *(const int*)b;
}
