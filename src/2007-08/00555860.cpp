// from server: 100% by colin
struct UnifiedWidget {
    char pad[0xfc];
    int menuState;
    void setMenuState(int value);
};

void UnifiedWidget::setMenuState(int value) {
    if (menuState != value) {
        menuState = value;
        (*(void (__thiscall **)(UnifiedWidget *))(*(int *)this + 0x68))(this);
    }
}
