// from server: 75% by atomic.potato
struct S {
    void f(float *p);
};

void S::f(float *p)
{
    p[0] = ((float *)this)[0];
    p[1] = ((float *)this)[1];
    p[2] = ((float *)this)[2];
    ((int *)p)[3] = ((int *)this)[3];
    ((int *)p)[4] = ((int *)this)[4];
    ((int *)p)[5] = ((int *)this)[5];
    ((int *)p)[6] = ((int *)this)[6];
}
