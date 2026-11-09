// from server: 100% by colin
struct Extents {
    float lowX;
    float lowY;
    float lowZ;
    float highX;
    float highY;
    float highZ;
    bool overlapsOrTouches(const Extents& other) const;
};

extern float g_81c3b8;
extern float g_82d030;

struct BlockBlockContact {
    char pad[0xc];
    int field_c;
    int field_10;
    char pad2[0x54 - 0x14];
    float field_54;
    bool check();
    bool testZero(float v);
    void slot0();
};

bool BlockBlockContact::check() {
    if (((Extents*)(field_c + 0x80))->overlapsOrTouches(*(Extents*)(field_10 + 0x80))) {
        if (testZero(0.0f)) {
            field_54 = g_81c3b8;
        } else {
            field_54 = g_82d030;
        }
    } else {
        field_54 = g_82d030;
    }
    slot0();
    return field_54 <= 0.0f;
}
