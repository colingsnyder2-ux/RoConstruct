// from server: 49% by atomic.potato
extern "C" char __stdcall sub_746690(int, int);

struct AxesComponentItem {
    char pad[0x128];
    int field_128;
    bool compare(int, int);
};

bool AxesComponentItem::compare(int a, int b) {
    char r1 = sub_746690(field_128, a);
    char r2 = sub_746690(field_128, b);
    return r1 == r2;
}
