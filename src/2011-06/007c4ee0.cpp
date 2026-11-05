// from server: 77% by atomic.potato
extern "C" void __cdecl sub_5529c0(void *, void *, void *, int);

struct Point
{
    int unused;
    int *p4;
    int *p8;
    Point *f(int);
};

Point *Point::f(int value)
{
    sub_5529c0((void *)value, p4 + 1, p8 + 1, 0);
    return (Point *)value;
}
