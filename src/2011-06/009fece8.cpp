// from server: 68% by atomic.potato
extern "C" void __cdecl func_0080b1d8(void *, unsigned int, unsigned int, const void *);

struct S_seg_009f0000
{
    void func_009fece8();
};

void S_seg_009f0000::func_009fece8()
{
    int *p = (int *)((char *)this + 0x34);
    func_0080b1d8(p, 0x10, 4, (const void *)0x40d4a0);
}
