// from server: 73% by atomic.potato
extern "C" void *sub_76f9d0(void *, void *);
extern "C" void sub_76a190(void *, void *);

struct EnumDesc
{
    void f(void *);
};

void EnumDesc::f(void *arg)
{
    void *p = sub_76f9d0(this, (char *)arg + 4);
    void *value = *(void **)p;
    sub_76a190(this, &value);
}
