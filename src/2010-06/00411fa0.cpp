// from server: 48% by atomic.potato
struct CAboutRobloxDialog {
    void sub_401810(int);
    char pad[0x24];
    int field_28;
    int field_2c;
    int field_30;
    int field_34;
    int field_38;
    CAboutRobloxDialog* __cdecl init(int);
};

CAboutRobloxDialog* CAboutRobloxDialog::init(int arg) {
    sub_401810(arg);
    field_28 = 0xa00968;
    field_2c = 0;
    field_30 = 0;
    field_34 = 0;
    field_38 = -1;
    *(int*)this = 0xa02d18;
    field_28 = 0xa02d10;
    return this;
}
