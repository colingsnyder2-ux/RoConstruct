// from server: 90% by Yeetserama
struct CSettingsDialog {
    virtual ~CSettingsDialog() {}
    virtual void vfunc1() = 0;
    virtual void vfunc2() = 0;
    virtual void vfunc3() = 0;
    virtual bool CheckKey(int keyCode) = 0;
    int CheckInputKeys();
};

int CSettingsDialog::CheckInputKeys() {
    if (CheckKey(0x77)) goto Ltrue;
    if (CheckKey(0x73)) goto Ltrue;
    if (CheckKey(0x61)) goto Ltrue;
    if (CheckKey(0x64)) goto Ltrue;
    if (CheckKey(0x111)) goto Ltrue;
    if (CheckKey(0x112)) goto Ltrue;
    if (CheckKey(0x114)) goto Ltrue;
    if (CheckKey(0x113)) goto Ltrue;
    return 0;
Ltrue:
    return 1;
}
