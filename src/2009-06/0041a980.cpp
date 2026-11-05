// from server: 100% by why2
struct CInstanceRecord {
    struct CNameItem {
        void f();
    };
};

void CInstanceRecord::CNameItem::f() {
    char* p = *(char**)this;
    *p = *(char*)((char*)this + 4);
}
