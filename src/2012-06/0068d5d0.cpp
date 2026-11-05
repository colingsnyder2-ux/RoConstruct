// from server: 42% by Intel
struct VModelInstanceFactoryProduct {
    void* vftable;
    int field_4;
    int field_8;
    int field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    char pad_38[36];
};

extern "C" void __stdcall G3D_Sphere_Copy(void* dst, const void* src);

VModelInstanceFactoryProduct* __stdcall VModelInstanceFactoryProduct_ctor(
    VModelInstanceFactoryProduct* this_,
    void* vftable,
    const int* vec3_a,
    float f1,
    float f2,
    float f3,
    const int* vec3_b
) {
    this_->vftable = vftable;
    this_->field_4 = vec3_a[0];
    this_->field_8 = vec3_a[1];
    this_->field_C = vec3_a[2];
    this_->field_10 = f1;
    this_->field_14 = f2;
    this_->field_18 = f3;
    this_->field_1C = *reinterpret_cast<const float*>(&vec3_b[0]);

    this_->field_20 = 0;
    this_->field_24 = 0;
    this_->field_28 = 0;
    this_->field_2C = 0;
    this_->field_30 = 0;
    this_->field_34 = 0;

    G3D_Sphere_Copy(reinterpret_cast<char*>(this_) + 0x38, vec3_b);

    return this_;
}
