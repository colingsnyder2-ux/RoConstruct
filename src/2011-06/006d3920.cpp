// from server: 100% by atomic.potato
struct JointInstance
{
    void f();
};

extern "C" void G1_func_006d3080();

void JointInstance::f()
{
    *(int *)this = 0xaa61ac;
    *((int *)this + 1) = 0xaa61a4;
    *((int *)this + 6) = 0xaa6198;
    *((int *)this + 7) = 0xaa618c;
    *((int *)this + 0x24) = 0xaa6164;
    G1_func_006d3080();
}
