// from server: 75% by atomic.potato
struct UDimItem {
    char pad0[0x20];
    char pad20[0xec];
    int field_10c;
    char pad110[0x18];
    int field_128;
    int field_12c;
    void* init(int a, int b);
};

void* UDimItem::init(int a, int b) {
    void (*fn)(UDimItem*, int, int) = (void (*)(UDimItem*, int, int))0x459c80;
    fn(this, a, b);
    field_12c = 0;
    field_128 = 0;
    *(int*)this = 0xb55eac;
    *(int*)((char*)this + 0x20) = 0xb55e4c;
    field_10c = 0xb55e44;

    return this;
}
