// from server: 100% by tajop
extern int g_vtbl0;
extern int g_vtbl4;
extern int g_vtbl18;
extern int g_vtbl1c;

struct GlobalAdvancedSettingsItem {
    int* vtbl0;
    int* vtbl4;
    char pad08[0x10];
    int* vtbl18;
    int* vtbl1c;
    static GlobalAdvancedSettingsItem* sing;
    void destroyBase();
    GlobalAdvancedSettingsItem* scalarDeletingDestructor(unsigned int flags);
};

GlobalAdvancedSettingsItem* GlobalAdvancedSettingsItem::scalarDeletingDestructor(unsigned int flags) {
    sing = 0;
    vtbl0 = &g_vtbl0;
    vtbl4 = &g_vtbl4;
    vtbl18 = &g_vtbl18;
    vtbl1c = &g_vtbl1c;
    destroyBase();
    if (flags & 1) {
        operator delete(this);
    }
    return this;
}
