// from server: 100% by colin
struct RBX_LaserTool {
    double getValue();
};

double RBX_LaserTool::getValue()
{
    (*(void (__thiscall **)(void *))(*(int *)this + 0x44))(this);
    return *(double *)((char *)this + 0xe8);
}
