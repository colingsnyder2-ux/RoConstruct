// from server: 44% by atomic.potato
extern "C" double __cdecl Convert(unsigned int, unsigned int, unsigned int, unsigned int);

struct S
{
    unsigned int a[116];
    unsigned int b;
    double f();
};

double S::f()
{
    unsigned int v[2];
    Convert(b, a[0], 1000, 0);
    v[0] = ((unsigned int*)0)[0];
    v[1] = ((unsigned int*)0)[1];
    return *(double*)v * *(double*)0x9de530;
}
