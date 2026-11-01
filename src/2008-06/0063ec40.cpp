// from server: 100% by tester
struct SlingshotTool {
    char pad[36];
    bool flag28;
    char pad2[0x30 - 0x29];
    int field30;
    void sub_5fc540(int);
    void func(int);
};

void SlingshotTool::func(int a) {
    if (flag28 && field30 == 0) {
        sub_5fc540(a);
    }
}
