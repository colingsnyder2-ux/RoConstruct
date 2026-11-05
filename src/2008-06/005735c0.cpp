// from server: 100% by tester
struct UnifiedWidget {
    char pad[0x144];
    int menuState;
    void setMenuState(int value);
};

void UnifiedWidget::setMenuState(int value) {
    if (menuState != value) {
        menuState = value;
        (*(void (__thiscall **)(UnifiedWidget *))(*(int *)this + 0x64))(this);
    }
}
