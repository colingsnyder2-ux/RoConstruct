// from server: 100% by atomic.potato
struct CRenderSettingsItem
{
    int m_padding[3];
    int m_value;
    int __cdecl f(int value);
};

int CRenderSettingsItem::f(int value)
{
    return m_value == value;
}
