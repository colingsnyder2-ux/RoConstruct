// from server: 47% by atomic.potato
extern "C" unsigned int __cdecl func_009048e0();

struct RotateConnector {
    char pad0[0x7c];
    float m_field7C;
    unsigned char m_field80;
    void set(float value);
};

void RotateConnector::set(float value) {
    unsigned int count = func_009048e0();
    float result = value / (float)count;
    m_field7C = result;
    if (value == *(float*)0xb53ac8) {
        m_field80 = 1;
    }
}
