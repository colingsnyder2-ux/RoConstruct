// from server: 77% by atomic.potato
struct S
{
    int f(void *);
};

extern "C" void *__cdecl sub_67b500(void *);
extern "C" void sub_76a190(S *, void *);

int S::f(void *arg)
{
    void *value = *(void **)sub_67b500((char *)arg + 4);
    sub_76a190(this, &value);
    return 0;
}
