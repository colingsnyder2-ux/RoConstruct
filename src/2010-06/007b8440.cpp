// from server: 100% by tester
struct CXTPCommandBar {
    void SetVisible(int bVisible);
};

void CXTPCommandBar::SetVisible(int bVisible) {
    *(int*)(*(int*)((char*)this + 0x178) + 0x14) = bVisible;
    (*(void (__thiscall**)(CXTPCommandBar*, int, int))(*(int*)this + 0x1ac))(this, 0, 1);
}