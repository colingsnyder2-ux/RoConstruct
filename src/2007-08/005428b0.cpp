// from server: 100% by colin
struct RBX_VInstance_SignalDesc {
    unsigned char m_SignalDesc;
};

extern RBX_VInstance_SignalDesc G1_008bfac0;

unsigned char func_005428b0() {
    return G1_008bfac0.m_SignalDesc;
}
