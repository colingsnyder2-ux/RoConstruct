// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Notifier { void fire(const void* what); };
struct CRenderSettingsItem {
    char pad[0x88];
    int value;
    char pad2[0x144-0x8c];
    Notifier changed;
    void setValue(int v);
};
extern int gItem;
void CRenderSettingsItem::setValue(int v) {
    if (v != value) { value = v; changed.fire(&gItem); }
}