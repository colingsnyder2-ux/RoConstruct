// from server: 100% by colin
struct CMainFrame {
    char pad[0x134];
    int field_0x134;
    void func(int arg);
};

void CMainFrame::func(int arg)
{
    int result = (*(int (__thiscall **)(void *))(*(int *)this + 0x188))(this);
    if (result == 0)
        this->field_0x134 = arg;
}
