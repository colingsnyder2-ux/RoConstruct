// from server: 68% by atomic.potato
extern "C" void __stdcall sub_407630(int, int, int, int);

struct S
{
    void f();
};

void S::f()
{
    int value = *(int*)((char*)0 + 0xb79500);
    sub_407630(value, 0x6e, *(int*)((char*)0 + 4), 0);
}
