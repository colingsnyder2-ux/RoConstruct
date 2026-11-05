// from server: 65% by atomic.potato
struct ManualGlueJoint
{
    int f(int, int, int, int);
};

int ManualGlueJoint::f(int a, int b, int c, int d)
{
    *(int *)this = 0xABD07C;
    *((int *)this + 1) = a;
    *((int *)this + 2) = c;
    *((int *)this + 3) = *(int *)b;
    *((int *)this + 4) = *(int *)d;
    *(int *)this = 0xABD09C;
    return 0;
}
