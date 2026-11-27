// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct Desc;
extern Desc g_desc;
struct Sig { int x; void raise(const Desc* d); };
struct CRenderSettingsItem
{
    char pad[0xb4];
    int value;
    char pad2[0x144 - 0xb8];
    Sig sig;
    void SetValue(int value);
};
void CRenderSettingsItem::SetValue(int v)
{
    if (v != value)
    {
        value = v;
        sig.raise(&g_desc);
    }
}
