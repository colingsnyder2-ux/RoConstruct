// from server: 100% by atomic.potato
extern "C" unsigned char __stdcall sub_00926e25(int, int);

struct S
{
    void f();
};

void S::f()
{
    *(unsigned char *)0x00ba1f8d = sub_00926e25(0, 0x900);
}
