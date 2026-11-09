// from server: 100% by colin
struct RBX_ArrowTool {
    char pad[0x14];
    bool flag;
    void method();
};

void RBX_ArrowTool::method()
{
    if (flag) {
        (*(void (__thiscall **)(void *))(*(int *)this + 0x24))(this);
    }
}
