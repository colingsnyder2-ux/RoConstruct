// from server: 100% by tester
struct RBX_SlingshotTool {
    int field0;
    char pad[0x10];
    char field14;
    char pad2[0x1b];
    int field30;
    void method(int);
};

void RBX_SlingshotTool::method(int arg)
{
    if (field30 > 0) {
        field30 = field30 - 1;
    }
    if (field14 != 0) {
        void (__thiscall *fn)(RBX_SlingshotTool*, int);
        fn = *(void (__thiscall **)(RBX_SlingshotTool*, int))(*(int*)this + 0x18);
        fn(this, arg);
    }
}
