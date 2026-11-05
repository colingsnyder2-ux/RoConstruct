// from server: 100% by colin
struct CXTPRibbonControls {
    char pad[0x20];
    void* field20;
    int IsItemInGroup(void* item);
};

int CXTPRibbonControls::IsItemInGroup(void* item) {
    void* p = *(void**)((char*)item + 0x154);
    if (p != 0) {
        if (*(void**)((char*)p + 0x68) == item)
            return 1;
        if (*(void**)((char*)p + 0x6c) == item)
            return 1;
    }
    void* c = *(void**)((char*)field20 + 0x264);
    if (item == c)
        return 1;
    c = *(void**)((char*)field20 + 0x268);
    if (item == c)
        return 1;
    c = *(void**)((char*)field20 + 0x26c);
    if (item == c)
        return 1;
    c = *(void**)((char*)field20 + 0x1d0);
    if (item == c)
        return 1;
    return item == *(void**)((char*)field20 + 0x1d4);
}
