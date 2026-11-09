// from server: 79% by atomic.potato
struct S
{
    int f(int);
};

struct T
{
    int value;
};

extern "C" T * sub_76e3e0(int);
extern "C" int sub_76a190(S *, T *);

int S::f(int value)
{
    T *p = sub_76e3e0(value + 4);
    T t;
    t.value = p->value;
    return sub_76a190(this, &t);
}
