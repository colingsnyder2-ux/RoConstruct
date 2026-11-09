// from server: 60% by Intel
struct RBX_VServiceProvider_EventDesc {
    char pad0[0xb94];
    bool m_EventDesc;

    bool f();
};
bool RBX_VServiceProvider_EventDesc::f()
{
    return m_EventDesc;
}
