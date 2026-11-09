// from server: 100% by tester
struct CXTMaskEditT {
    void OnNotify(int, int);
    void sub_63023E();
};

void CXTMaskEditT::OnNotify(int code, int pNotify) {
    if (code == -0x14) {
        if (*(unsigned int*)(pNotify + 4) & 0x400000) {
            void (__thiscall *fn)(CXTMaskEditT*) = *(void (__thiscall **)(CXTMaskEditT*))(*(int*)this + 0x164);
            fn(this);
            *(int*)((char*)this + 0xa4) = 1;
        }
    }
    sub_63023E();
}
