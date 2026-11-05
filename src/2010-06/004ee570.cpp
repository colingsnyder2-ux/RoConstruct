// from server: 61% by atomic.potato
extern "C" int* __cdecl sub_004aadb0(int);

struct S
{
    void __cdecl f(int, int);
};

void S::f(int a, int b)
{
    int* p = sub_004aadb0(b);
    a = *p;
    *(int*)b = a;
}
