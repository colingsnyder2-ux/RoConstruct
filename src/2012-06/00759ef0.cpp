// from server: 53% by atomic.potato
extern "C" int __cdecl sub_759DE0(unsigned long long, const char *, int);

struct S {
    void f(unsigned long long *);
};

void S::f(unsigned long long *p)
{
    unsigned long long v = *p;
    unsigned int lo = (unsigned int)v;
    unsigned int hi = (unsigned int)(v >> 32);
    unsigned int sign = hi & 0x80000000;
    unsigned int mag = hi & 0x7fffffff;
    unsigned long long m = ((unsigned long long)mag << 32) | lo;
    double d = (double)(long long)m;
    if (sign)
        d = -d;
    sub_759DE0((unsigned long long)d, "%llu", 0);
}
