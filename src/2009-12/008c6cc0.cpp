// from server: 100% by atomic.potato
struct CXTMaskEditT {
    char pad[0xa4];
    int field_a4;
    void sub_7f3e30();
    void OnChar(unsigned int nChar, void* p);
};

void CXTMaskEditT::OnChar(unsigned int nChar, void* p) {
    if (nChar == 0xffffffec) {
        if ((*(unsigned int*)((char*)p + 4) & 0x400000) != 0) {
            (*(void (__thiscall**)(CXTMaskEditT*))(*(int*)this + 0x164))(this);
            field_a4 = 1;
        }
    }
    sub_7f3e30();
}
