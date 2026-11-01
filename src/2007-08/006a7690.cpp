// from server: 100% by colin
struct CXTPRibbonBar {
    char pad[0x168];
    int field_168;
    int field_16c;
    int field_170;
    void sub_6ca460();
    CXTPRibbonBar* init(int a, int b);
};

CXTPRibbonBar* CXTPRibbonBar::init(int a, int b) {
    sub_6ca460();
    field_168 = b;
    *(int*)this = 0x7d46bc;
    *(int*)((char*)this + 0x20) = 0x7d465c;
    field_170 = a;
    field_16c = 0;
    return this;
}
