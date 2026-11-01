// from server: 100% by colin
struct CArray {
    char pad[0x2c];
    int m_data;
    int Find(int) const;
    void RemoveAt(int, int);
    void Remove(int);
};

void CArray::Remove(int value) {
    CArray* sub = (CArray*)((char*)this + 0x2c);
    int idx = sub->Find(value);
    if (idx != -1)
        sub->RemoveAt(idx, 1);
}
