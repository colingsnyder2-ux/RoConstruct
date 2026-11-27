// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Sig { void notify(void* p); };
static int g;
struct CRenderSettingsItem {
    char pad[0xc4]; int value; char pad2[0x144-0xc8]; Sig sig;
    void SetValue(int v);
};
void CRenderSettingsItem::SetValue(int v)
{
    if (v != value) { value = v; sig.notify(&g); }
}
