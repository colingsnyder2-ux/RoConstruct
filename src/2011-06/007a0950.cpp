// from server: 32% by atomic.potato
struct S {
    int v[7];
    void f(const int* p);
};

void S::f(const int* p)
{
    v[0] = p[0];
    v[1] = p[1];
    v[2] = p[2];
    v[3] = p[3];
    v[4] = p[4];
    v[5] = p[5];
    v[6] = p[6];
}
