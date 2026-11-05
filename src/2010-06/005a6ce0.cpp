// from server: 59% by atomic.potato
struct S
{
    int f(int);
    void *field_1c;
};

struct T
{
    int value;
    int type;
    int result;
};

struct V
{
    int (**vtable)();
};

extern "C" int sub_005dfd30(T *);

int S::f(int arg)
{
    T *p = (T *)field_1c;
    int value = ((int (*)(void *, int))(*(int **)p + 12))(p, arg);
    T *q = (T *)((char *)this + 16);
    sub_005dfd30(q);
    q->result = value;
    q->type = 5;
    return 0;
}
