// from server: 76% by atomic.potato
struct S
{
    void f(void *a, unsigned int b, unsigned int c);
};

void S::f(void *a, unsigned int b, unsigned int c)
{
    if (c != 4)
    {
        *(unsigned int *)((char *)a + 0) = c;
        return;
    }

    *(unsigned int *)b = 0x00de8330;
    *((unsigned char *)b + 4) = 0;
    *((unsigned char *)b + 5) = 0;
}
