// from server: 79% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int sub_7c5f00(int);

int sub_76a190(S *, int *);

int S::f(int value)
{
    int result = sub_7c5f00(value + 4);
    int temp = *(int *)result;
    return sub_76a190(this, &temp);
}
