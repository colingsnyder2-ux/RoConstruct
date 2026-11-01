// from server: 100% by colin
struct HVCXTPPropertyGridItem
{
    int XItem;
};

bool __stdcall compareItems(HVCXTPPropertyGridItem* a, HVCXTPPropertyGridItem* b)
{
    return a->XItem == b->XItem;
}
