// from server: 100% by colin
struct CPropertyGridItemBrickColor {
    char pad[0x100];
    int field_100;
    int field_104;
    void Set(void* p);
};

void CPropertyGridItemBrickColor::Set(void* p) {
    field_104 = (int)p;
    if (p != 0) {
        *(int*)p = field_100;
    }
}
