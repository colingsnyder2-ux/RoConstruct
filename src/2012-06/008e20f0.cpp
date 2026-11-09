// from server: 100% by Intel
struct VCRenderSettingsItem {
    void EnumPropDescriptor(int value);
};

extern "C" void __stdcall sub_414da0(int);

void VCRenderSettingsItem::EnumPropDescriptor(int value) {
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xB0) != value) {
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xB0) = value;
        sub_414da0(0xE55928);
    }
}
