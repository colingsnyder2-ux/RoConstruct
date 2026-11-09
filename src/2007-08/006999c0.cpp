// from server: 100% by colin
struct CXTPPropertyGridItemConstraints {
    char pad0[0x28];
    int m_count;
    int GetItemIndex(int index);
    int FindItem(int value);
};

int CXTPPropertyGridItemConstraints::FindItem(int value)
{
    int i = 0;
    if (m_count > 0) {
        do {
            int item = GetItemIndex(i);
            if (value == *(int*)((char*)item + 0x24))
                return i;
            ++i;
        } while (i < m_count);
    }
    return -1;
}
