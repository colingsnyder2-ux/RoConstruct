// from server: 73% by atomic.potato
extern "C" int *sub_76ee60(void *, int *);
extern "C" int sub_76a190(void *, int *);

struct S
{
    void f(int *);
};

void S::f(int *p)
{
    int v = *sub_76ee60(this, p + 1);
    sub_76a190(this, &v);
}
