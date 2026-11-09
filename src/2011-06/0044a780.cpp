// from server: 49% by atomic.potato
struct FacesComponentItem {
    char pad[0x128];
    void* field_128;
    bool compare(void* a, void* b);
};

extern "C" char __stdcall sub_651c00(void* a, void* b);

bool FacesComponentItem::compare(void* a, void* b) {
    char r1 = sub_651c00(field_128, a);
    char r2 = sub_651c00(field_128, b);
    return r1 == r2;
}
