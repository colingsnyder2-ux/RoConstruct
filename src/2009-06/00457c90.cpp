// from server: 100% by tester
struct CRobloxView {
    char pad[0x20c];
    int field_198;
    void method(int);
};

void CRobloxView::method(int arg) {
    int* p = (int*)arg;
    int* vtbl = (int*)*p;
    int flag = (this->field_198 != 0) ? 1 : 0;
    typedef void (__thiscall *Fn)(void*, int);
    Fn fn = (Fn)vtbl[1];
    fn((void*)arg, flag);
}