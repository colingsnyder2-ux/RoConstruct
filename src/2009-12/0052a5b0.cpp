// from server: 40% by atomic.potato
// roc 2009-12 0052a5b0  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052a5b0

extern "C" float __stdcall sub_52F0F0();
extern "C" void __stdcall sub_52EE70(void*, void*, int);
extern "C" void __stdcall sub_52F040(void*, void*, int, int);

extern float g_9aea18;
extern float g_9bc6a0;

struct VCRenderSettingsItem {
    void sub_52A4B0(float v);
    void sub_52A5B0(float a, float b, float c);
};

void VCRenderSettingsItem::sub_52A5B0(float a, float b, float c) {
    float len = 0.0f;
    float tmp = 0.0f;
    float sq = a * a + b * b + c * c;
    float root = 0.0f;
    root = sq;
    len = root;
    tmp = root;
    if (sub_52F0F0()) {
        sub_52EE70(&tmp, &len, 4);
        sub_52F040(this, &len, 0x20, 1);
    } else {
        sub_52F040(this, &len, 0x20, 1);
    }
    if (len > g_9bc6a0) {
        float inv = g_9aea18 / len;
        float v = inv * a;
        sub_52A4B0(v);
        v = inv * b;
        sub_52A4B0(v);
        v = inv * c;
        sub_52A4B0(v);
    }
}
