// from server: 100% by why2
struct RBX_VerticalCylinderBuilder {
    char pad[0x70];
    bool flag;
    float get() const;
};

extern float g_value;

float RBX_VerticalCylinderBuilder::get() const {
    if (flag)
        return g_value;
    return 1.0f;
}
