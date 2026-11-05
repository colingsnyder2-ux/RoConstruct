// from server: 89% by tajop
extern void *ShirtGraphic_vftable0[];
extern void *ShirtGraphic_vftable4[];
extern void *ShirtGraphic_vftable18[];
extern void *ShirtGraphic_vftable1C[];
extern void *ShirtGraphic_vftable80[];
extern int ShirtGraphic_instanceCount;
int makeField28();

struct LegacyBase {
    void **vt0;
    void **vt4;
    char pad8[0x10];
    void **vt18;
    void **vt1c;
    char pad20[8];
    int field28;
    char pad2c[0x54];
    void **vt80;
    LegacyBase();
    ~LegacyBase();
};

struct ShirtGraphic : LegacyBase {
    ShirtGraphic();
};

ShirtGraphic::ShirtGraphic() {
    vt0 = ShirtGraphic_vftable0;
    vt4 = ShirtGraphic_vftable4;
    vt18 = ShirtGraphic_vftable18;
    vt1c = ShirtGraphic_vftable1C;
    vt80 = ShirtGraphic_vftable80;
    field28 = makeField28();
    ++ShirtGraphic_instanceCount;
}
