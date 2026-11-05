// from server: 34% by atomic.potato
// roc 2009-12 005662c0  unit: RakPeer  size: 57 bytes
// float RakPeer::getSomething()

struct RakPeer {
    char pad[0xa00];
    unsigned int m_count;
    int m_value;
    float getRatio();
};

float RakPeer::getRatio() {
    unsigned int count = m_count;
    if (count == 0)
        return 0.0f;
    int value = m_value;
    float fv = (float)value;
    if (value < 0)
        fv += 4294967296.0f;
    float fc = (float)count;
    if ((int)count < 0)
        fc += 4294967296.0f;
    return fv / fc;
}
