// from server: 79% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int sub_76df30(int *);
extern "C" int sub_76a190(S *, int *);

int S::f(int value)
{
    int temp;
    temp = *(int *)sub_76df30((int *)(value + 4));
    return sub_76a190(this, &temp);
}
