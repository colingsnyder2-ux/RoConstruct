// from server: 100% by tester
struct CAboutRobloxDialog {
    int Method(int);
};

int CAboutRobloxDialog::Method(int)
{
    struct VTable {
        char pad[0x160];
        void (__thiscall *fn)(CAboutRobloxDialog*);
    };
    VTable* vt = *(VTable**)this;
    vt->fn(this);
    return 0;
}