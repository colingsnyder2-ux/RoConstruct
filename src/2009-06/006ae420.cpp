// from server: 100% by why2
struct RotateConnector {
    int get(int which);
    int m_pad0;
    int m_pad4;
    int m_field8;
    int m_fieldC;
};

int RotateConnector::get(int which) {
    if (which == 0)
        return m_field8;
    return m_fieldC;
}
