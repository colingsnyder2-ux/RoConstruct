// from server: 100% by atomic.potato
struct CPropertyGridItemBrickColor
{
    char padding[36];
    int* items;
    int count;
    int GetItem(int index);
};

int CPropertyGridItemBrickColor::GetItem(int index)
{
    if (index < 0 || index >= count)
        return 0;
    return items[index];
}
