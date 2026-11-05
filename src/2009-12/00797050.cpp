// from server: 100% by atomic.potato
extern "C" void __cdecl sub_00788ba0(int, int, int);

struct S
{
    int pad[3];
    int value;
    void f();
};

void S::f()
{
    sub_00788ba0(value, -1, 0);
}
