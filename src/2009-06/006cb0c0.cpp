// from server: 100% by why2
struct SlingshotTool {
    char pad[0x24];
    char flag24;
    char pad2[0x2c - 0x25];
    int field2c;
    void method(int);
    void helper(int);
};

void SlingshotTool::method(int arg) {
    if (flag24 != 0 && field2c == 0) {
        helper(arg);
    }
}
