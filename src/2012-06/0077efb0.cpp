// from server: 79% by atomic.potato
extern "C" void *sub_76d750(const void *);
extern "C" void sub_76a190(void *, const void *);

struct EnumDesc
{
    void f(const void *);
};

void EnumDesc::f(const void *arg)
{
    void *value = sub_76d750((const char *)arg + 4);
    void *item = *(void **)value;
    sub_76a190(this, &item);
}
