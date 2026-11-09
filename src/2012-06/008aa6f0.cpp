// from server: 65% by atomic.potato
struct ConstraintSurfacePair
{
    int value0;
    int value1;
    int value2;
    int value3;
    int value4;
    int f(int, int, int, int);
};

int ConstraintSurfacePair::f(int a, int b, int c, int d)
{
    value1 = a;
    value0 = 0x00be0658;
    value2 = c;
    value3 = *(int*)b;
    value4 = *(int*)d;
    value0 = 0x00be06b8;
    return 0;
}
