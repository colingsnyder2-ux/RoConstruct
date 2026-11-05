// from server: 82% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __cdecl sub_007a8ade(void *, unsigned int, unsigned int, const void *);

struct QuadVolumeBuilder
{
    void f();
};

void QuadVolumeBuilder::f()
{
    sub_007a8ade((char *)this + 4, 4, 16, (const void *)0x52caf0);
}
