// from server: 38% by atomic.potato
extern "C" void __stdcall sub_7A799A(void*);

struct VCRenderSettingsItem {
    char pad[8];
    void* field_8;
    void* GlobalSettingsItem(void* arg);
};

void* VCRenderSettingsItem::GlobalSettingsItem(void* arg) {
    if ((reinterpret_cast<unsigned int>(arg) & 1) != 0) {
        sub_7A799A(this);
    }

    return this;
}
