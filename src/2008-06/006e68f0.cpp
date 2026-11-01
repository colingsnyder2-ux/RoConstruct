// from server: 100% by tester
struct CXTPDockingPaneManager {
    char pad[0x128];
    int field_128;
    void sub_66fa00(int);
    void sub_66e100(int);
    void sub_66ec00();
    void sub_6301e4();
    void func(int);
};

void CXTPDockingPaneManager::func(int arg) {
    if (arg != 0) {
        int v = ((int (__thiscall *)(void *))((*(int **)this)[0x144 / 4]))(this);
        field_128 = v;
        sub_66e100(v);
        sub_66ec00();
    } else {
        sub_66fa00(field_128);
        int v = field_128;
        if (v != 0) {
            ((CXTPDockingPaneManager *)v)->sub_6301e4();
            field_128 = 0;
        }
    }
}
