// from server: 73% by colin
struct CXTPRibbonBar {
    void sub_6A7F90();
};

struct Helper178 {
    void sub_6FEBF0(int, int, int);
};

void CXTPRibbonBar::sub_6A7F90() {
    int* p264 = *(int**)((char*)this + 0x264);
    if (p264 != 0) {
        Helper178* h = (Helper178*)((char*)p264 + 0x178);
        h->sub_6FEBF0(*(int*)((char*)this + 0x20), -1, -1);
    }
    int* p274 = *(int**)((char*)this + 0x274);
    if (p274 != 0) {
        int rect[4];
        rect[0] = p274[0x34 / 4];
        rect[1] = p274[0x38 / 4];
        rect[2] = p274[0x3c / 4];
        rect[3] = p274[0x40 / 4];
        int* vt = *(int**)this;
        void (__thiscall* fn)(CXTPRibbonBar*, int*, int) = (void (__thiscall*)(CXTPRibbonBar*, int*, int))vt[0x19c / 4];
        *(int**)((char*)this + 0x274) = 0;
        fn(this, rect, 1);
    }
    ((void (__thiscall*)(CXTPRibbonBar*))0x6443E0)(this);
}
