// from server: 100% by atomic.potato
struct CXTPStatusBar
{
    int GetItem(int);
    int GetItemData(int);
};

int CXTPStatusBar::GetItemData(int index)
{
    int value = GetItem(index);
    if (!value)
        return 0;
    return *(int *)((char *)value + 0x28);
}
