// from server: 71% by atomic.potato
struct S
{
    void f(const S* p);
};

void S::f(const S* p)
{
    ((int*)this)[0] = ((const int*)p)[0];
    ((int*)this)[1] = ((const int*)p)[1];
    ((int*)this)[2] = ((const int*)p)[2];
    ((int*)this)[3] = ((const int*)p)[3];
}
