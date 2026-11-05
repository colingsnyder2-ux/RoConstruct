// from server: 72% by Intel
struct ConstraintSurfacePair {
    void* vftable;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    short field_14;
    short field_16;
    short field_18;

    ConstraintSurfacePair* __thiscall ctor(ConstraintSurfacePair* this_,
    int a2,
    int a3,
    int a4,
    int a5);
};

extern "C" int g_vftable_1;
extern "C" int g_vftable_2;

ConstraintSurfacePair* __thiscall ConstraintSurfacePair::ctor(
    ConstraintSurfacePair* this_,
    int a2,
    int a3,
    int a4,
    int a5
) {
    this_->field_4 = a2;
    this_->vftable = &g_vftable_1;
    this_->field_8 = a3;
    int v5 = *reinterpret_cast<int*>(a4);
    this_->field_C = v5;
    int v6 = *reinterpret_cast<int*>(a5);
    this_->field_10 = v6;
    this_->vftable = &g_vftable_2;
    this_->field_14 = 0;
    this_->field_16 = 0;
    this_->field_18 = 0;
    return this_;
}
