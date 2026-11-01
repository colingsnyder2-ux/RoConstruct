// from server: 100% by colin
struct CXTPReportControl {
    int getSomeValue() const;
};

int CXTPReportControl::getSomeValue() const {
    int value = *(int*)((char*)this + 0x180);
    value = (value != 0) ? 2 : 0;
    return value | 0x81;
}
