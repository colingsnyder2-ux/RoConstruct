// from server: 31% by atomic.potato
struct CRenderSettings {
    char pad[0x1ea];
    unsigned char field_0x1ea;
    void setFlag(int mode, unsigned char flag);
};

void CRenderSettings::setFlag(int mode, unsigned char flag) {
    if (flag) {
        field_0x1ea = (mode != 2);
    } else {
        field_0x1ea = (mode == 1);
    }
}
