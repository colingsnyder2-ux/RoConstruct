// from server: 100% by why2
struct CAboutRobloxDialog {
    int sub_00401230(int);
};

int CAboutRobloxDialog::sub_00401230(int)
{
    void (CAboutRobloxDialog::*p)() = *(void (CAboutRobloxDialog::**)())(*(void***)this + 0x160 / 4);
    (this->*p)();
    return 0;
}
