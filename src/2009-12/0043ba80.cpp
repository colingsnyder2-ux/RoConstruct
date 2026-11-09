// from server: 49% by atomic.potato
struct AxesComponentItem {
    char pad[0x130];
    void* field130;
    bool compare(void* a, void* b);
};

extern "C" bool __stdcall sub_6b2f10(void* a, void* b);

bool AxesComponentItem::compare(void* a, void* b) {
    bool r1 = sub_6b2f10(field130, a);
    bool r2 = sub_6b2f10(field130, b);
    return r1 == r2;
}
