// from server: 73% by atomic.potato
extern "C" int sub_76a7a0(void *, void *);
extern "C" int sub_76a190(void *, void *);

struct S
{
    int f(void *);
};

int S::f(void *arg)
{
    int value = *(int *)sub_76a7a0(this, (char *)arg + 4);
    return sub_76a190(this, &value);
}
