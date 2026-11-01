// from server: 93% by atomic.potato
struct CXTPPropertyGridItemConstraints
{
    char pad0[0x28];
    int count;
    int GetAt(int index);
    int Find(int value);
};

int CXTPPropertyGridItemConstraints::Find(int value)
{
    int i = 0;
    if (count > 0)
    {
        do
        {
            if (GetAt(i) == value)
                return i;
            ++i;
        } while (i < count);
    }
    return -1;
}
