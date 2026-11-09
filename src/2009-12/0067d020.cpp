// from server: 60% by atomic.potato
struct S
{
    int f();
};

extern "C" int sub_0067bd30(S *, int);

int S::f()
{
    int *p = (int *)sub_0067bd30((S *)((char *)this + 0x14), 1);
    int *q = (int *)p[0x26];
    unsigned int n = ((unsigned int)q[4] - (unsigned int)q[3]) >> 3;
    return n != 0;
}
