// from server: 65% by atomic.potato
struct ManualGlueJoint
{
    int f(int a, int b, int c, int d);
};

int ManualGlueJoint::f(int a, int b, int c, int d)
{
    *(int *)this = 0xabd07c;
    *((int *)this + 1) = a;
    *((int *)this + 2) = c;
    *((int *)this + 3) = *(int *)b;
    *((int *)this + 4) = *(int *)d;
    *(int *)this = 0xabd08c;
    return 0;
}
