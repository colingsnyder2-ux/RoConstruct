// from server: 85% by atomic.potato
struct KernelJoint
{
    int __stdcall f(int* a, int* b, int* c, int* d);
};

int __stdcall KernelJoint::f(int* a, int* b, int* c, int* d)
{
    if (b[*a + 0x48] == 2 || d[*c + 0x48] == 2)
        return 1;
    return 0;
}
