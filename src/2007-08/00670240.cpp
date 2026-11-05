// from server: 61% by colin
struct CXTPDockingPaneManager {
    int field0;
    int field4;
    int field8;
    int fieldC;
    void sub_66E4F0();
    void sub_66E000(int, int, int, int);
    int func(int, int);
};

int CXTPDockingPaneManager::func(int a, int b) {
    int v;
    field0 = a;
    field4 = *(int*)(b + 4);
    field8 = *(int*)(b + 8);
    fieldC = *(int*)(b + 0xC);
    sub_66E4F0();
    if (*(int*)((char*)&a + 4) != 0) {
        v = 9;
    } else {
        v = (*(int*)((char*)&a + 0x1C) != 0) ? 1 : 5;
    }
    sub_66E000(v, 0, 0, 0);
    return 1;
}
