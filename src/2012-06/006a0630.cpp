// from server: 33% by atomic.potato
struct S {
    char pad[0x2c];
    int field_2c;
    void method1(int, int, int, int);
    void method2(int, int, int, int);
};

void S::method1(int a, int b, int c, int d)
{
    int *p = (int *)(field_2c + a);
    method2(b, c, (int)(p ? (char *)p + 0x1c : 0), d);
}
