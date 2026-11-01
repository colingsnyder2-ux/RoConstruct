// from server: 100% by colin
struct CXTPDockingPaneMiniWnd {
    void f(int);
};

void CXTPDockingPaneMiniWnd::f(int) {
    (*(void (__thiscall **)(void *, int))(*((int *)this) + 0x38))(this, 0);
    (*(void (__thiscall **)(void *))(*((int *)this) + 0x28))(this);
}
