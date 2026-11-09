// from server: 75% by colin
struct CRenderSettings {
    char pad[0xe8];
    float field_e8;
    float field_ec;
    void sub_447410(float);
    void sub_444710(const char*);
    void setSomething(float);
};

void CRenderSettings::setSomething(float value) {
    float v = value;
    float* pe = &field_ec;
    if (field_ec != v) {
        sub_447410(v);
        v = *(float*)&value;
    }
    if (field_ec == v) {
        pe = &v;
    }
    float r = *pe;
    float zero = 0.0f;
    float tmp = r;
    if (tmp == *(double*)0x78fee0) {
        tmp = zero;
    }
    if (tmp != field_e8) {
        field_e8 = tmp;
        sub_444710((const char*)0x8bbc50);
    }
}
