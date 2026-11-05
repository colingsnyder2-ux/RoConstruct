// from server: 70% by Intel
struct RBX_VInstance_EventDesc {
    char pad[0x158];
    float m_x;

    float f();
};
float RBX_VInstance_EventDesc::f()
{
    return m_x;
}
