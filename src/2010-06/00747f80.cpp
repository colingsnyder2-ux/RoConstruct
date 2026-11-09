// from server: 100% by tester
struct SlingshotTool {
    char pad[0x14];
    bool flag14;
    char pad2[0x2c - 0x15];
    int field2c;
    void func(int);
};

void SlingshotTool::func(int a) {
    int v = field2c;
    if (v > 0) {
        field2c = v - 1;
    }
    if (flag14) {
        (*(void (__thiscall **)(SlingshotTool*, int))((*(char**)this) + 0x28))(this, a);
    }
}
