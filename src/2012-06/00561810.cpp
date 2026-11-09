// from server: 60% by atomic.potato
struct S
{
    void f(S *src);
};

void S::f(S *src)
{
    ((int *)this)[0] = ((int *)src)[0];
    ((int *)this)[1] = ((int *)src)[1];
    ((int *)this)[2] = ((int *)src)[2];
    ((int *)this)[3] = ((int *)src)[3];
    ((unsigned short *)this)[9] = ((unsigned short *)src)[9];
    ((unsigned short *)this)[8] = ((unsigned short *)src)[8];
}
