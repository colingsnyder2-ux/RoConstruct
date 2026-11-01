// from server: 100% by colin
struct CXTTreeBase_Map {
    char m_pad[0x264];
    void* m_slots[4];
    void SetSlot(int index, void* value);
};

void CXTTreeBase_Map::SetSlot(int index, void* value) {
    m_slots[index] = value;
}
