// from server: 69% by atomic.potato
extern "C" void __stdcall sub_963c10(int*, int*);

struct S
{
    int f(int);
};

int S::f(int a)
{
    int x;
    int y;
    sub_963c10(&x, &y);
    return x != *(int*)((char*)this + 0xa8);
}
