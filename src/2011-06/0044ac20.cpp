// from server: 76% by atomic.potato
struct AxesComponentItem {
    char pad[0x128];
    void* field_128;
    bool compare(void* other);
};

extern "C" bool __stdcall sub_652000(void* a, void* b);

bool AxesComponentItem::compare(void* other) {
    bool a = sub_652000(field_128, other);
    bool b = sub_652000(field_128, other);
    return a == b;
}
