// from server: 100% by Intel
struct CNameItem {
    void* field0;
    char field4;
    void setField0Byte();
};

void CNameItem::setField0Byte() {
    *reinterpret_cast<char*>(field0) = field4;
}
