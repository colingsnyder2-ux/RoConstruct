// from server: 100% by tester
struct CInstanceRecord_CNameItem {
    char* ptr;
    char value;
    void store();
};

void CInstanceRecord_CNameItem::store() {
    *ptr = value;
}
