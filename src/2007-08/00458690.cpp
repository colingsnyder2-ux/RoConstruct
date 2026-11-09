// from server: 49% by colin
struct CRobloxWnd {
    void* field0;
    CRobloxWnd* sub_458690(int a, int b);
};

extern "C" void* __cdecl sub_62FEF6(unsigned int size);

CRobloxWnd* CRobloxWnd::sub_458690(int a, int b) {
    void* p;
    this->field0 = 0;
    p = sub_62FEF6(0x14);
    if (p) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(int*)p = 0x7932d4;
        *(int*)((char*)p + 0xc) = a;
    } else {
        p = 0;
    }
    this->field0 = p;
    return this;
}
