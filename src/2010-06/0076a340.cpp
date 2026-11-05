// from server: 31% by atomic.potato
struct Point
{
    int padding0[3];
    int *field0c;
    int padding10[3];
    int field1c;
    int padding20[2];
    int field28;
    int field2c;

    void f();
};

extern "C" void __cdecl sub_714d30(int *, int *);

void Point::f()
{
    int *p = field0c;
    int *q = (int *)p[11];
    if (q[13])
        sub_714d30(&field28, &field1c);
}
