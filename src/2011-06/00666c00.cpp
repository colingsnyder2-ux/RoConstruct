// from server: 87% by atomic.potato
struct VCRenderSettingsItem_EnumPropDescriptor
{
    unsigned char m_value;
    unsigned char m_state;
    int f();
};

int VCRenderSettingsItem_EnumPropDescriptor::f()
{
    if (m_value)
        return 1;
    return -static_cast<int>(m_state) >> 31;
}
