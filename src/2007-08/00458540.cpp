// from server: 100% by colin
struct CRobloxWnd {
    void m();
    char pad[0x74];
    void* field_74;

    void func_00458540(char arg);
};

void CRobloxWnd::func_00458540(char arg) {
    if (arg == 0) {
        void* p = this->field_74;
        if (p != 0) {
            ((CRobloxWnd*)p)->m();
        }
    }
}
