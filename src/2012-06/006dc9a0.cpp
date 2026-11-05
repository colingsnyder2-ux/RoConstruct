// from server: 69% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int sub_006da210(S *, int);
extern "C" int sub_0076a190(S *, int *);

int S::f(int value)
{
    int result;
    result = sub_006da210(this, value + 4);
    result = *(int *)result;
    return sub_0076a190(this, &result);
}
