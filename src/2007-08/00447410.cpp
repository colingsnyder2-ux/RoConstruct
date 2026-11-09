// from server: 53% by colin
struct CRenderSettings {
    char pad[0xe8];
    float field_e8;
    float field_ec;
    void sub_447370(float);
    void sub_444710(const char*);
    void setAASamples(float);
};

extern float g_78fef0;
extern double g_78fee8;
extern const char g_8bbc6c[];

void CRenderSettings::setAASamples(float value) {
    float local8;
    float local10;
    float* p;

    if (field_e8 != value) {
        sub_447370(value);
        value = local10;
    }

    if (field_e8 == value) {
        p = &local10;
    } else {
        p = &local10;
    }

    local10 = *p;
    local8 = g_78fef0;

    if (local10 == (float)g_78fee8) {
        p = &local8;
    } else {
        p = &local10;
    }

    local10 = *p;

    if (local10 != field_ec) {
        field_ec = local10;
        sub_444710(g_8bbc6c);
    }
}
