// from server: 100% by colin
struct CInstanceRecord_CNameItem {
    char* ptr;
    char value;
    void store();
};

void CInstanceRecord_CNameItem::store() {
    *ptr = value;
}
