// from server: 31% by atomic.potato
extern "C" void __stdcall _invalid_parameter_noinfo();

struct EdgeEdgePair {
    char pad[0xc];
    int m_start;
    int m_end;
    int f(unsigned int idx);
};

int EdgeEdgePair::f(unsigned int idx) {
    int count = (m_end - m_start) / 0x14;
    if (idx >= (unsigned int)count) {
        _invalid_parameter_noinfo();
    }
    return m_start + idx * 0x14;
}
