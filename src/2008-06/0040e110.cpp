// from server: 100% by tester
struct CBrowserView {
    char pad[0x118];
    int field_0x104;
    void method(int* arg);
};

void CBrowserView::method(int* arg) {
    int* p = arg;
    int flag = (this->field_0x104 != 0) ? 1 : 0;
    typedef void (__thiscall *Fn)(void*, int);
    Fn fn = *(Fn*)(*p);
    fn(p, flag);
}
