// from server: 100% by tester
struct UnifiedWidget {
    char pad[0xa8];
    int menuState;
    void setMenuState(int value);
};

void UnifiedWidget::setMenuState(int value) {
    if (menuState != value) {
        menuState = value;
        (*(void (__thiscall **)(UnifiedWidget *))(*(int *)this + 0x78))(this);
    }
}
