// from server: 100% by colin
struct CXTPRibbonBar {
    char pad[0x264];
    void* field_264;
    void* GetItem(int index);
};

void* CXTPRibbonBar::GetItem(int index) {
    char* base = (char*)field_264 + 0x178;
    if (index >= 0 && index < *(int*)(base + 0x5c))
        return *(void**)(*(int*)(base + 0x58) + index * 4);
    return 0;
}
