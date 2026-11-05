// from server: 49% by atomic.potato
struct FacesComponentItem {
    char pad[0x130];
    void* field_130;
    bool compare(void* a, void* b);
};

extern "C" bool __stdcall sub_620710(void* a, void* b);

bool FacesComponentItem::compare(void* a, void* b) {
    bool r1 = sub_620710(field_130, a);
    bool r2 = sub_620710(field_130, b);
    return r1 == r2;
}
