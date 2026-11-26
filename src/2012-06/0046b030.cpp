// from server: 100% by Xemicl
// roc-cl: 30729
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
struct Sub { void update(int); };
struct CRenderSettingsItem
{
    char padding[0x4c];
    int value;
    char pad2[0xc0 - 0x4c - 4];
    Sub sub;
    void set(int v);
};

void CRenderSettingsItem::set(int v)
{
    if (v != value)
    {
        value = v;
        sub.update(0xe19980);
    }
}