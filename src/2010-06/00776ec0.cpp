// from server: 77% by atomic.potato
extern "C" void __cdecl sub_004e5f50(int);

struct S
{
    int value;
    int *ptr;
    void f();
};

void S::f()
{
    sub_004e5f50(ptr[60]);
}
