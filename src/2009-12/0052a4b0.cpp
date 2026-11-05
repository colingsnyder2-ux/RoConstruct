// from server: 23% by atomic.potato
// roc 2009-12 0052a4b0  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052a4b0

extern "C" int __stdcall sub_52f0f0(int);
extern "C" void __stdcall sub_52f040(void*, int, int);
extern "C" void __stdcall sub_52ee70(void*, void*, int);

struct VCRenderSettingsItem_EnumPropDescriptor {
    void func(float);
};

void VCRenderSettingsItem_EnumPropDescriptor::func(float arg) {
    float v0 = arg;
    float v1 = *(float*)0x9ab804;
    float v2 = *(float*)0x9aea18;
    if (v1 < v0) {
        v0 = v1;
    } else if (v0 > v2) {
        v0 = v2;
    }
    v0 = v0 + v2;
    v0 = v0 * *(float*)0x9bc69c;
    unsigned short s = (unsigned short)(int)v0;
    int local = s;
    if (sub_52f0f0(local)) {
        char buf[8];
        sub_52ee70(buf, &local, 2);
        sub_52f040(this, 0x10, 1);
    } else {
        sub_52f040(this, 0x10, 1);
    }
}
