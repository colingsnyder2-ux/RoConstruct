// from server: 100% by tester
struct RBX_LaserTool {
    double getValue();
};

double RBX_LaserTool::getValue()
{
    (*(void (__thiscall **)(void *))(*(int *)this + 0x5c))(this);
    return *(double *)((char *)this + 0x90);
}