// from server: 58% by atomic.potato
struct S
{
    void f(float *p);
    char data[0x168];
};

void S::f(float *p)
{
    char *a = *(char **)(data + 0x168);
    a = *(char **)(a + 0xf0);
    p[0] = *(float *)(a + 4);
    p[1] = *(float *)(a + 8);
    p[2] = *(float *)(a + 12);
}
