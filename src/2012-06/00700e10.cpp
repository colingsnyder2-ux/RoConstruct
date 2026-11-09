// from server: 96% by atomic.potato
extern "C" void __stdcall sub_700d70(int, int, int, int);

struct S
{
    void f(int, int);
    int pad[12];
    int m30;
    int m34;
};

void S::f(int a, int b)
{
    int value = a ? a - 28 : 0;
    sub_700d70(value, m30, m34, b + 4);
}
