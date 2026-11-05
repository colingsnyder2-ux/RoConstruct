// from server: 100% by tester
struct VCRenderSettingsItem {
    int EnumPropDescriptor();
};

int VCRenderSettingsItem::EnumPropDescriptor() {
    int* ptr = *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x20);
    int* vtable = *reinterpret_cast<int**>(ptr);
    int func = vtable[2];
    return reinterpret_cast<int(__thiscall*)(int*)>(func)(ptr);
}