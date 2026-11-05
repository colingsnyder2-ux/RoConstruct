// from server: 100% by why2
struct PartDataSource {
    char pad[0x1c];
    int field_0x1c;
    int getValue();
};

int PartDataSource::getValue() {
    int p = field_0x1c;
    if (p != 0) {
        return *(int*)(p + 0x20c);
    }
    return 0;
}
