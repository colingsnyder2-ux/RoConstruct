// from server: 49% by Intel




struct VAuthoringSettingsFactoryProduct {
    int m_capacity;
    int m_position;
    char* m_buffer;
    bool GetNext(char* out);
};

bool VAuthoringSettingsFactoryProduct::GetNext(char* out) {
    int pos = m_position;
    int aligned = (pos + 7) & ~7;
    m_position = aligned;
    int nextPos = aligned + 24;
    if (nextPos > m_capacity) {
        return false;
    }
    int byteIndex = aligned >> 3;
    char flag = m_buffer[byteIndex];
    if (!flag) {
        out[0] = flag;
        out[1] = m_buffer[byteIndex + 1];
        out[2] = m_buffer[byteIndex + 2];
        out[3] = 0;
    } else {
        out[3] = flag;
        out[2] = m_buffer[byteIndex + 1];
        out[1] = m_buffer[byteIndex + 2];
        out[0] = 0;
    }
    m_position += 24;
    return true;
}
